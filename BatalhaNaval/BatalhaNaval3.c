#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0
#define AREA_HABILIDADE 5
#define TAMANHO_HABILIDADE 5

// Função para imprimir o tabuleiro com legendas
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf(". ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == AREA_HABILIDADE) {
                printf("* ");
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

// Verifica se há sobreposição
int temSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] != AGUA) {
            return 1;
        }
    }
    return 0;
}

// Posiciona navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Gera a matriz da habilidade Cone (5x5)
void gerarCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2 - i) && j <= (TAMANHO_HABILIDADE / 2 + i)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera a matriz da habilidade Cruz (5x5)
void gerarCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera a matriz da habilidade Octaedro (5x5)
void gerarOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - TAMANHO_HABILIDADE / 2) + abs(j - TAMANHO_HABILIDADE / 2) <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - offset + i;
            int colunaTabuleiro = origemColuna - offset + j;
            // Verifica limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                if (matriz[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = AREA_HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // -----------------------------
    // NAVIOS (Novato + Aventureiro)
    // -----------------------------

    // Horizontal
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int linhaHArr[TAMANHO_NAVIO], colunaHArr[TAMANHO_NAVIO];
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            linhaHArr[i] = linhaH;
            colunaHArr[i] = colunaH + i;
        }
        if (!temSobreposicao(tabuleiro, linhaHArr, colunaHArr, TAMANHO_NAVIO)) {
            posicionarNavio(tabuleiro, linhaHArr, colunaHArr, TAMANHO_NAVIO);
        }
    }

    // Vertical
    int linhaV = 4, colunaV = 7;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int linhaVArr[TAMANHO_NAVIO], colunaVArr[TAMANHO_NAVIO];
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            linhaVArr[i] = linhaV + i;
            colunaVArr[i] = colunaV;
        }
        if (!temSobreposicao(tabuleiro, linhaVArr, colunaVArr, TAMANHO_NAVIO)) {
            posicionarNavio(tabuleiro, linhaVArr, colunaVArr, TAMANHO_NAVIO);
        }
    }

    // Diagonal ↘
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int linhaD1Arr[TAMANHO_NAVIO], colunaD1Arr[TAMANHO_NAVIO];
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            linhaD1Arr[i] = linhaD1 + i;
            colunaD1Arr[i] = colunaD1 + i;
        }
        if (!temSobreposicao(tabuleiro, linhaD1Arr, colunaD1Arr, TAMANHO_NAVIO)) {
            posicionarNavio(tabuleiro, linhaD1Arr, colunaD1Arr, TAMANHO_NAVIO);
        }
    }

    // Diagonal ↙
    int linhaD2 = 0, colunaD2 = 9;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - TAMANHO_NAVIO + 1 >= 0) {
        int linhaD2Arr[TAMANHO_NAVIO], colunaD2Arr[TAMANHO_NAVIO];
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            linhaD2Arr[i] = linhaD2 + i;
            colunaD2Arr[i] = colunaD2 - i;
        }
        if (!temSobreposicao(tabuleiro, linhaD2Arr, colunaD2Arr, TAMANHO_NAVIO)) {
            posicionarNavio(tabuleiro, linhaD2Arr, colunaD2Arr, TAMANHO_NAVIO);
        }
    }

    // -----------------------------
    // HABILIDADES (Mestre)
    // -----------------------------

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaed
