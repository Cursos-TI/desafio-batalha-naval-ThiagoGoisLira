#include <stdio.h>

// Desenvolvendo um jogo de batalha naval simples em C
// Curso de ADS - Estacio 2025
// Desafio nivel NOVATO
// Thiago J Gois (Código revisado)

int main(){

    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};// Array para representar as colunas do tabuleiro
    int tabuleiro[10][10];// Tabuleiro 10x10 para o jogo de batalha naval


    for (int i = 0; i < 10; i++){// Inicializando o tabuleiro
        for (int j = 0; j < 10; j++){// Loop para inicializar cada posição do tabuleiro
            tabuleiro[i][j] = 0;// Inicializando todas as posições do tabuleiro com 0
        }
    }
    // Posicionando os navios no tabuleiro navio orizontal
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    // Posicionando os navios no tabuleiro navio vertical
    tabuleiro[6][5] = 3;
    tabuleiro[7][5] = 3;
    tabuleiro[8][5] = 3;

    printf("  "); // Espaço inicial para alinhar as colunas
    for (int i = 0; i < 10; i++){// Loop para imprimir as letras das colunas
        printf(" %c ", linha[i]);// Imprimindo as letras das colunas
    }

    for (int i = 0; i < 10; i++){// Loop para imprimir o tabuleiro
        printf("\n%d ", i);// Imprimindo os números das linhas
        for (int j = 0; j < 10; j++){// Loop para imprimir cada posição do tabuleiro
            printf(" %d ", tabuleiro[i][j]); // Imprimindo o valor da posição do tabuleiro
        }
    }
    
    printf("\n"); // Adiciona uma quebra de linha no final
    return 0;

}