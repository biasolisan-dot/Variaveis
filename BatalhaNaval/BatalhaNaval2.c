#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se há sobreposição
int temSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] != AGUA) {
            return 1; // true
        }
    }
    return 0; // false
}

// Função para posicionar o navio (assume que já foi validado)
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // -----------------------------
    // Navio 1 - Horizontal
    // -----------------------------
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

    // -----------------------------
    // Navio 2 - Vertical
    // -----------------------------
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

    // -----------------------------
    // Navio 3 - Diagonal Principal ↘
    // -----------------------------
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

    // -----------------------------
    // Navio 4 - Diagonal Secundária ↙
    // -----------------------------
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
    // Imprimir o tabuleiro
    // -----------------------------
    imprimirTabuleiro(tabuleiro);

    return 0;
}
