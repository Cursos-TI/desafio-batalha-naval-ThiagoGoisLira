#include <stdio.h>

// Desenvolvendo um jogo de batalha naval simples em C
// Curso de ADS - Estacio 2025
// Desafio nivel MESTRE
// Thiago J Gois

#define LINHAS 10    // Define o número de linhas do tabuleiro
#define COLUNAS 10   // Define o número de colunas do tabuleiro
#define HABILIDADE 5 // Define o tamanho da matriz de habilidade (ex: 5x5)

#define AGUA 0   // Representa a água
#define NAVIO 3  // Representa um navio
#define EFEITO 5 // Representa a área de efeito de uma habilidade

int main() {
    
    
    char linha[COLUNAS] = {'A','B','C','D','E','F','G','H','I','J'};// Array para os rótulos das colunas (A-J)
    int tabuleiro[LINHAS][COLUNAS];// Matriz principal do jogo

    for (int i = 0; i < LINHAS; i++) {// Loop para preencher todo o tabuleiro com ÁGUA (0)
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navio horizontal (3 células)
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    
    // Navio vertical (3 células)
    tabuleiro[3][2] = NAVIO;
    tabuleiro[4][2] = NAVIO;
    tabuleiro[5][2] = NAVIO;

    // Navio diagonal (3 células)
    for(int k = 0; k < 3; k++){// Verifica se o navio cabe nos limites do tabuleiro
        if (5+k < LINHAS && 5+k < COLUNAS) {
            tabuleiro[5+k][5+k] = NAVIO;
        }
    }
    
    // Navio anti-diagonal (3 células)
    for(int k = 0; k < 3; k++){
        if (5+k < LINHAS && 3-k >= 0) {// Verifica os limites
            tabuleiro[5+k][3-k] = NAVIO;
        }
    }

    // Criando Matrizes de Habilidade (5x5)
    int matrizCone[HABILIDADE][HABILIDADE];
    int matrizCruz[HABILIDADE][HABILIDADE];
    int matrizOctaedro[HABILIDADE][HABILIDADE];
 
    int centroSkill = HABILIDADE / 2;// Calcula o índice do centro da matriz de habilidade (5 / 2 = 2)
    
    // Lógica para criar a Habilidade CONE
    // (Forma de triângulo/cone que começa de cima)
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {// Lógica do cone: expande a cada linha 'i'
            if (j >= centroSkill - i && j <= centroSkill + i) {
                matrizCone[i][j] = 1; // 1 = Área de efeito
            } else {
                matrizCone[i][j] = 0; // 0 = Sem efeito
            }
        }
    }

    for (int i = 0; i < HABILIDADE; i++) {// Lógica para criar a Habilidade CRUZ
        for (int j = 0; j < HABILIDADE; j++) {// Afeta se estiver na linha central (i) OU na coluna central (j)
            if (i == centroSkill || j == centroSkill) {
                matrizCruz[i][j] = 1;
            } else {
                matrizCruz[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < HABILIDADE; i++) {// Lógica para criar a Habilidade OCTAEDRO
        for (int j = 0; j < HABILIDADE; j++) {
            
            // Calcula a distância da célula (i) até o centro
            int dist_i = i - centroSkill;
            if (dist_i < 0) {
                dist_i = -dist_i; // Pega o valor absoluto (sempre positivo)
            }
            
            // Calcula a distância da célula (j) até o centro
            int dist_j = j - centroSkill;
            if (dist_j < 0) {
                dist_j = -dist_j;
            }

            // Lógica do losango (Distância de Manhattan)
            if (dist_i + dist_j <= centroSkill) {
                matrizOctaedro[i][j] = 1;
            } else {
                matrizOctaedro[i][j] = 0;
            }
        }
    }

    //Aplicando Habilidade CONE no Tabuleiro
    // Ponto de origem (topo do cone)
    int origLinhaCone = 1;
    int origColunaCone = 6;
    
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            // Se a matriz de skill for 1 (afeta)
            if (matrizCone[i][j] == 1) {
                // Calcula a posição no tabuleiro
                int deltaLinha = i; // Cone começa do topo (linha 0 da skill)
                int deltaColuna = j - centroSkill; // Coluna é relativa ao centro
                int boardLinha = origLinhaCone + deltaLinha;
                int boardColuna = origColunaCone + deltaColuna;

                // Verifica se a posição está DENTRO dos limites do tabuleiro
                if (boardLinha >= 0 && boardLinha < LINHAS && boardColuna >= 0 && boardColuna < COLUNAS) {
                    // Marca o tabuleiro com o efeito
                    tabuleiro[boardLinha][boardColuna] = EFEITO;
                }
            }
        }
    }

    //Aplicando Habilidade CRUZ no Tabuleiro 
    // Ponto de origem (centro da cruz)
    int origLinhaCruz = 4;
    int origColunaCruz = 4;
    
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            // Se a matriz de skill for 1 (afeta)
            if (matrizCruz[i][j] == 1) {
                // Calcula o deslocamento a partir do centro da skill
                int deltaLinha = i - centroSkill;
                int deltaColuna = j - centroSkill;
                // Calcula a posição final no tabuleiro
                int boardLinha = origLinhaCruz + deltaLinha;
                int boardColuna = origColunaCruz + deltaColuna;

                // Verifica limites do tabuleiro
                if (boardLinha >= 0 && boardLinha < LINHAS && boardColuna >= 0 && boardColuna < COLUNAS) {
                    tabuleiro[boardLinha][boardColuna] = EFEITO;
                }
            }
        }
    }

    //Aplicando Habilidade OCTAEDRO
    // Ponto de origem (centro do losango)
    int origLinhaOcta = 7;
    int origColunaOcta = 7;
    
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            // Se a matriz de skill for 1 (afeta)
            if (matrizOctaedro[i][j] == 1) {
                // Lógica de sobreposição (igual à Cruz, centrada)
                int deltaLinha = i - centroSkill;
                int deltaColuna = j - centroSkill;
                int boardLinha = origLinhaOcta + deltaLinha;
                int boardColuna = origColunaOcta + deltaColuna;

                // Verifica limites do tabuleiro
                if (boardLinha >= 0 && boardLinha < LINHAS && boardColuna >= 0 && boardColuna < COLUNAS) {
                    tabuleiro[boardLinha][boardColuna] = EFEITO;
                }
            }
        }
    }

    // Exibindo o Tabuleiro Final
    printf("\n--- Tabuleiro de Batalha Naval com Habilidades ---\n");
    printf("   "); // Espaço para alinhar com os números das linhas
    for (int i = 0; i < COLUNAS; i++) {
        printf(" %c ", linha[i]); // Imprime o cabeçalho
    }

    // Loop pelas linhas do tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("\n%d ", i); // Imprime o número da linha
        if (i < 10) printf(" "); // Alinhamento extra para números de 1 dígito

        // Loop pelas colunas do tabuleiro
        for (int j = 0; j < COLUNAS; j++) {
            // Verifica o valor em cada célula e imprime o número correspondente
            switch (tabuleiro[i][j]) {
                case AGUA:
                    printf(" 0 "); // Água
                    break;
                case NAVIO:
                    printf(" 3 "); // Navio
                    break;
                case EFEITO:
                    printf(" 5 "); // Área de efeito da Habilidade
                    break;
                default:
                    printf(" ? "); // Para caso apareça valor inesperado
                    break;
            }
        }
    }
    
    // Imprime a legenda final
    printf("\n\nLegenda: [0] Agua | [3] Navio | [5] Efeito de Habilidade\n");
    printf("\n");
    
    return 0; // Fim do programa
}
