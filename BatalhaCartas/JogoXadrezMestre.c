#include <stdio.h>

// Função recursiva para o movimento da Torre (para a Direita)
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento da Rainha (para a Esquerda)
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função recursiva para o Bispo (Cima Direita)
void moverBispo(int casas) {
    if (casas <= 0) return;
    printf("Cima Direita\n");
    moverBispo(casas - 1);
}

// Movimento do Cavalo usando loops aninhados
void moverCavalo(int movimentos) {
    printf("Movimento do Cavalo (em 'L', 2 para cima e 1 para direita):\n");
    int movimentosFeitos = 0;

    for (int i = 1; i <= 3; i++) { // Simula tentativas de movimento
        for (int j = 1; j <= 3; j++) {
            if (i == 2 && j == 1) { // Movimento típico do cavalo em 'L'
                printf("Cima\n");
                printf("Cima\n");
                printf("Direita\n");
                movimentosFeitos++;
            }

            if (movimentosFeitos >= movimentos) break; // Limita movimentos
        }
        if (movimentosFeitos >= movimentos) break;
    }
}

// Bispo com loops aninhados (simulando diagonal Cima Direita)
void moverBispoComLoop(int casas) {
    printf("Movimento do Bispo com loops aninhados (Diagonal Cima Direita):\n");

    for (int i = 1; i <= casas; i++) { // Movimento vertical
        for (int j = 1; j <= 1; j++) { // Movimento horizontal acoplado
            printf("Cima Direita\n");
        }
    }
}

int main() {
    // Número de casas para cada peça
    int casasTorre = 5;
    int casasRainha = 8;
    int casasBispo = 5;
    int movimentosCavalo = 1;

    // --- Movimento da Torre com Recursividade ---
    printf("Movimento da Torre (5 casas para a Direita):\n");
    moverTorre(casasTorre);
    printf("\n");

    // --- Movimento do Bispo com Recursividade ---
    printf("Movimento do Bispo (5 casas na Diagonal Cima Direita):\n");
    moverBispo(casasBispo);
    printf("\n");

    // --- Movimento da Rainha com Recursividade ---
    printf("Movimento da Rainha (8 casas para a Esquerda):\n");
    moverRainha(casasRainha);
    printf("\n");

    // --- Movimento do Cavalo com Loops Aninhados ---
    moverCavalo(movimentosCavalo);
    printf("\n");

    // --- Movimento do Bispo com Loops Aninhados ---
    moverBispoComLoop(casasBispo);
    printf("\n");

    return 0;
}
