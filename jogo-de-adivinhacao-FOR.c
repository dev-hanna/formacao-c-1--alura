// Biblioteca que permite uso de entradas e saídas
#include <stdio.h>       

// Biblioteca para usar o tempo como semente para o número aleatório
#include <stdlib.h>

// Biblioteca para gerar número aleatório considerando os segundos de EPOCH
#include <time.h> 


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

    // Variáveis para armazenar as tentativas necessárias e o número de tentativas disponíveis
    int tentativas = 1;
    int numerotentativas;

    int acertou = 0;

    // Criando diferentes níveis de dificuldade, com base na quantidade de tentativas disponíveis
    int nivel;
    printf("Dificuldades disponíveis:\n");
    printf("(1) Fácil  (2) Médio  (3) Difícil\n\n");
    printf("Escolha o nível de dificuldade: \n\n");
    scanf("%d", &nivel);

    // Usando o SWITCH como método de escolha entre as opções
    switch(nivel) {
        case 1:
            numerotentativas = 20;
            break;
        case 2:
            numerotentativas = 15;
            break;
        default:
            numerotentativas = 6;
            break;
    }


    // Loop FOR para criar uma repetição, limitando o número de tentativas do usuário
    for (int i = 1; i <= numerotentativas; i++) {
        printf("Tentativa %d. \n\n", tentativas);
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
        } 
        
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        // Verificar se o chute está correto, ou se é maior ou menor que o número secreto
        if (chute == numerosecreto) {
            
            // Interrompe a execução do loop FOR
            break;      
        }         
        else if (maior) {
            printf("Tente novamente! Seu chute foi maior que o número secreto!\n\n");
        } else {
            printf("Tente novamente! Seu chute foi menor que o número secreto!\n\n");
        }         
        tentativas++;
    }

    // Mensagens de fim de jogo, avisando ao usuário se ele venceu ou não
    printf("Fim de jogo!\n");

    if (acertou) {
        printf("Parabéns! \n\n");
        printf("Você acertou com %d tentativas!\n\n", tentativas);
    } else {
        printf("Você perdeu! Tente novamente!");
    }
}

