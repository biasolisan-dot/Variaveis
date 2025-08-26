#include <stdio.h>
#include <string.h>

int main() {
    // --- Declaração das variáveis da Carta 1 ---
    char estado1, codigo1[4], nomeCidade1[100];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1, superPoder1;

    // --- Declaração das variáveis da Carta 2 ---
    char estado2, codigo2[4], nomeCidade2[100];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2, superPoder2;

    int opcao;

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
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);

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
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // --- MENU INTERATIVO ---
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - Exibir Nomes das Cidades\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nResultado da Comparação:\n");

    switch (opcao) {
        case 1:
            printf("População:\n");
            printf("%s: %lu habitantes\n", nomeCidade1, populacao1);
            printf("%s: %lu habitantes\n", nomeCidade2, populacao2);

            if (populacao1 > populacao2)
                printf("Vencedora: %s\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("Vencedora: %s\n", nomeCidade2);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Área:\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);

            if (area1 > area2)
                printf("Vencedora: %s\n", nomeCidade1);
            else if (area2 > area1)
                printf("Vencedora: %s\n", nomeCidade2);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("PIB:\n");
            printf("%s: %.2f bilhões de reais\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões de reais\n", nomeCidade2, pib2);

            if (pib1 > pib2)
                printf("Vencedora: %s\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("Vencedora: %s\n", nomeCidade2);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Número de Pontos Turísticos:\n");
            printf("%s: %d pontos\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomeCidade2, pontosTuristicos2);

            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Vencedora: %s\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Vencedora: %s\n", nomeCidade2);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidade2);

            if (densidade1 < densidade2)
                printf("Vencedora: %s (menor densidade)\n", nomeCidade1);
            else if (densidade2 < densidade1)
                printf("Vencedora: %s (menor densidade)\n", nomeCidade2);
            else
                printf("Empate!\n");
            break;

        case 6:
            printf("Nome da Cidade 1: %s\n", nomeCidade1);
            printf("Nome da Cidade 2: %s\n", nomeCidade2);
            printf("Este atributo é apenas informativo e não possui comparação.\n");
            break;

        default:
            printf("Opção inválida. Por favor, execute o programa novamente e escolha uma opção válida.\n");
            break;
    }

    return 0;
}
