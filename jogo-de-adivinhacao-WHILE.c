// Biblioteca que permite uso de entradas e saídas
#include <stdio.h>      

// Biblioteca para gerar número aleatório considerando os segundos de EPOCH
#include <time.h> 

// Biblioteca para usar o tempo como semente para o número aleatório
#include <stdlib.h>


// Função principal
int main() {  
    // printf: imprime na tela; \n: muda de linha       
    printf("\n*****************************************\n");       
    printf("** Boas vindas ao Jogo de Adivinhação! **\n");       
    printf("*****************************************\n\n");

    // Gerando um número aleatório usando EPOCH e Rand
    int segundos = time(0);
    srand(segundos);
    
    int numerogrande = rand();


    // int: variável que recebe um número inteiro como valor
    int numerosecreto = (numerogrande % 100) + 1;
    // O resto da divisão de 100 será entre 0 e 99; adicionando 1, o intervalo muda para 1 a 100


    // Variável para guardar o chute do usuário
    int chute;     
    
    // Variável booleana para determinar se o usuário ganhou ou não
    int ganhou = 0;

    // Variável para contar o número de tentativas necessárias para o acerto
    int tentativas = 0;


    /*Loop WHILE para criar uma repetição, a qual continuará ocorrendo enquanto o usuário não acertar o número secreto*/
    while (ganhou == 0) {
        printf("Tentativa %d. \n\n", tentativas + 1);
        printf("Qual é o seu chute? Escolha um número de 1 a 100: ");
        scanf("%d", &chute);
        /* scanf: lê o valor digitado pelo usuário 
        %d: máscara para retomar um valor, determinando que ele é um número inteiro 
        &chute: indica a variável onde esse valor será guardado */

        printf("\nSeu chute foi %d.\n\n", chute);

        // Verificando se o número é negativo
        if (chute < 0) {
            printf("Não pode chutar números negativos!\n\n");

            // Interrompe o loop, passando para a próxima interação do FOR (i++)
            continue;

        } else {
            // Verificar se o chute está correto, ou se é maior ou menor que o número secreto
            if (chute == numerosecreto) {
                printf("Parabéns! Você acertou!\n\n");
                
                // Interrompe a execução do loop WHILE
                ganhou = 1;      

            } else {
                if (chute > numerosecreto) {
                    printf("Tente novamente! Seu chute foi maior que o número secreto!\n\n");
                } else {
                    printf("Tente novamente! Seu chute foi menor que o número secreto!\n\n");
                }
            }
        } 
        tentativas++;
    }
    printf("Fim de jogo!\n");
    printf("Você acertou com %d tentativas!\n\n", tentativas);
}

