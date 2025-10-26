#include <stdio.h>

// Desenvolvendo um jogo de batalha naval simples em C
// Curso de ADS - Estacio 2025
// Desafio nivel AVENTUREIRO
// Thiago J Gois
#define LINHAS 10
#define COLUNAS 10
int main(){

    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};// Array para representar as colunas do tabuleiro
    int tabuleiro[LINHAS][COLUNAS];// Tabuleiro 10x10 para o jogo de batalha naval


    for (int i = 0; i < LINHAS; i++){// Inicializando o tabuleiro
        for (int j = 0; j < COLUNAS; j++){// Loop para inicializar cada posição do tabuleiro
            tabuleiro[i][j] = 0;// Inicializando todas as posições do tabuleiro com 0
        }
    }
    // Posicionando os navios no tabuleiro navio orizontal
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    // Posicionando os navios no tabuleiro navio vertical
    tabuleiro[3][2] = 3;
    tabuleiro[4][2] = 3;
    tabuleiro[5][2] = 3;

    for(int k = 0; k < 3; k++){// Posicionando o navio diagonal
        if (5+k < LINHAS && 5+k < COLUNAS) { // Verificando os limites do tabuleiro
            tabuleiro[5+k][5+k] = 3; // Posicionando o navio diagonal
        }
    }
    for(int k = 0; k < 3; k++){// Posicionando o navio anti-diagonal
        if (1+k < LINHAS && 8-k >= 0) {// Verificando os limites do tabuleiro
            tabuleiro[6+k][3-k] = 3;// Posicionando o navio anti-diagonal
        }
    }

    printf("  "); // Espaço inicial para alinhar as colunas
    for (int i = 0; i < COLUNAS; i++){// Loop para imprimir as letras das colunas
        printf(" %c ", linha[i]);// Imprimindo as letras das colunas
    }

    for (int i = 0; i < LINHAS; i++){// Loop para imprimir o tabuleiro
        printf("\n%d ", i);// Imprimindo os números das linhas
        for (int j = 0; j < COLUNAS; j++){// Loop para imprimir cada posição do tabuleiro
            printf(" %d ", tabuleiro[i][j]); // Imprimindo o valor da posição do tabuleiro
        }
    }
    
    printf("\n"); // Adiciona uma quebra de linha no final
    return 0;

}