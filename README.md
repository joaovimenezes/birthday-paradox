# Birthday Paradox 🎂
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![GitHub](https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white)

Após algumas pesquisas de problemas matemáticos, encontrei o Paradoxo do Aniversário, e busquei provar computacionalmente a probabilidade de colisão de aniversários em grupos de diferentes tamanhos.

## Birthday Paradox 🎉

O problema funciona da seguinte forma: em um grupo de N pessoas, qual é a probabilidade de pelo menos duas delas fazerem aniversário no mesmo dia? A intuição sugere que seriam necessárias cerca de 183 pessoas para atingir 50% de chance. A matemática, porém, surpreende: bastam apenas **23 pessoas**.

Matematicamente, a probabilidade de colisão é dada por:

```
P(colisão) = 1 - (364/365) × (363/365) × ... × ((365 - N + 1)/365)
```

## Funcionamento geral

O usuário define o tamanho do grupo e a quantidade de simulações. O programa sorteia aleatoriamente um aniversário para cada pessoa do grupo e verifica se há colisão. Ao final, exibe a probabilidade empírica obtida com base nas simulações realizadas.

## Estrutura do código

O programa foi elaborado em C e possui uma estrutura baseada em funções com responsabilidades bem definidas.

A função `randomGenerator(int range)` é responsável por gerar um número aleatório entre 0 e `range - 1`.

A função `birthdayGenerator()` utiliza o `randomGenerator` para sortear um dia do ano entre 0 e 364, representando os 365 dias.

A função `birthdaySimulator(int groupSize)` simula uma rodada completa. Ela utiliza um array auxiliar `calender[365]`, inicializado com zeros, para verificar se um aniversário já foi sorteado anteriormente. Ao encontrar a primeira colisão, retorna 1 imediatamente. Caso percorra todo o grupo sem colisão, retorna 0.

Por fim, a função `main()` controla toda a execução do programa. Ela inicializa a aleatoriedade com `srand(time(NULL))`, recebe o tamanho do grupo e a quantidade de simulações, executa as rodadas e exibe a probabilidade resultante. A execução ocorre dentro de um loop `do...while`, permitindo rodar múltiplos cenários sem reiniciar o programa.

## Conclusões computacionais

A partir das simulações realizadas, é possível observar na prática o comportamento esperado do paradoxo. Ao executar um grande número de rodadas, os resultados convergem para os valores teóricos previstos, conforme descreve a Lei dos Grandes Números.

### Grupo de 10 pessoas
Probabilidade teórica esperada: ~11,70%. Exemplo computacional com 1 milhão de simulações:
```bash
simulations: 1000000
group size: 10
same birthdays: 116948
probability: 11.69%
```

### Grupo de 23 pessoas
Probabilidade teórica esperada: ~50,70%. Exemplo computacional com 1 milhão de simulações:
```bash
simulations: 1000000
group size: 23
same birthdays: 507243
probability: 50.72%
```

### Grupo de 50 pessoas
Probabilidade teórica esperada: ~97,00%. Exemplo computacional com 1 milhão de simulações:
```bash
simulations: 1000000
group size: 50
same birthdays: 970183
probability: 97.02%
```

### Grupo de 365 pessoas
Probabilidade teórica esperada: ~99,9999%. Exemplo computacional com 1 milhão de simulações:
```bash
simulations: 1000000
group size: 365
same birthdays: 1000000
probability: 100.00%
```