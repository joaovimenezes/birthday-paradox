#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomGenerator(int range){
    return rand() % range; //0 -> (range - 1): range und  
}

int birthdayGenarator(){
    return randomGenerator(365);
}

int birthdaySimulator(int groupSize){
    int calender[365] = {0};

    for (int j = 0; j < groupSize; j++){
        int birthday = birthdayGenarator();

        if (calender[birthday] == 1){
                return 1;
        } else {
            calender[birthday] = 1;
        }
    }
    return 0;
}

int main(){
    int g = 0;

    srand(time(NULL));

    do {
        int i = 0;
        int sameBirthday = 0; int simulations = 0; int groupSize = 0;

        printf("simulations:\n>> ");
        scanf("%d", &simulations);

        printf("group size:\n>> ");
        scanf("%d", &groupSize);

        do {
            sameBirthday+= birthdaySimulator(groupSize);
            i++;
        } while (i < simulations);

        printf("same birthdays: %d\n", sameBirthday);
        printf("probability: %.2f%%\n", (sameBirthday * 100.0 / simulations));

        printf("quit: 0\nstay: 1\n>> ");
        scanf("%d", &g);
    } while (g == 1);
}