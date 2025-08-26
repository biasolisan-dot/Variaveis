#include <stdio.h>
#include <string.h>

int main() {
    // --- Declaração das variáveis da Carta 1 ---
    char estado1, codigo1[4], nomeCidade1[100];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    // --- Declaração das variáveis da Carta 2 ---
    char estado2, codigo2[4], nomeCidade2[100];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    int atributo1, atributo2;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    float soma1 = 0, soma2 = 0;

    // --- Entrada de dados da Carta 1 ---
    printf("Cadastro da Carta 1\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a População: ");
    scanf("%lu", &populacao1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Cálculos da Carta 1 ---
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;

    // --- Entrada de dados da Carta 2 ---
    printf("\nCadastro da Carta 2\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a População: ");
    scanf("%lu", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos da Carta 2 ---
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // --- Menu: Escolha do primeiro atributo ---
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // --- Menu: Escolha do segundo atributo ---
    printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    // --- Atribuição dos valores para o PRIMEIRO atributo ---
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontosTuristicos1; valor1_c2 = pontosTuristicos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
        case 6: valor1_c1 = pibPerCapita1; valor1_c2 = pibPerCapita2; break;
    }

    // --- Atribuição dos valores para o SEGUNDO atributo ---
    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontosTuristicos1; valor2_c2 = pontosTuristicos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
        case 6: valor2_c1 = pibPerCapita1; valor2_c2 = pibPerCapita2; break;
    }

    // --- Lógica de comparação com operador ternário ---
    printf("\n=== Resultado da Comparação ===\n");
    printf("Cidade 1: %s\n", nomeCidade1);
    printf("Cidade 2: %s\n", nomeCidade2);

    printf("\nComparando Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f → ",
           nomeCidade1, valor1_c1,
           nomeCidade2, valor1_c2);
    printf("%s venceu!\n",
           (atributo1 == 5) ? (valor1_c1 < valor1_c2 ? nomeCidade1 : (valor1_c2 < valor1_c1 ? nomeCidade2 : "Empate!")) :
                              (valor1_c1 > valor1_c2 ? nomeCidade1 : (valor1_c2 > valor1_c1 ? nomeCidade2 : "Empate!")));

    printf("\nComparando Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
        case 6: printf("PIB per Capita\n"); break;
    }
    printf("%s: %.2f | %s: %.2f → ",
           nomeCidade1, valor2_c1,
           nomeCidade2, valor2_c2);
    printf("%s venceu!\n",
           (atributo2 == 5) ? (valor2_c1 < valor2_c2 ? nomeCidade1 : (valor2_c2 < valor2_c1 ? nomeCidade2 : "Empate!")) :
                              (valor2_c1 > valor2_c2 ? nomeCidade1 : (valor2_c2 > valor2_c1 ? nomeCidade2 : "Empate!")));

    // --- Soma dos valores para decisão final ---
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c
