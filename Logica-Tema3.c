#include <stdio.h>

int main() {

    // Carta 1
    char estado1[20], codigo1[20], cidade1[20];
    int pontosT1;
    float area1, pib1, densidade1, pibpc1;      // pibpc = PIB per capita
    unsigned long int populacao1;

    // Carta 2
    char estado2[20], codigo2[20], cidade2[20];
    int pontosT2;
    float area2, pib2, densidade2, pibpc2;
    unsigned long int populacao2;

    int escolha_atributo;

    // ===== Cadastro Carta 1 =====
    printf("Cadastro da Carta 1\n");

    printf("Estado: ");
    scanf("%19s", estado1);

    printf("Codigo: ");
    scanf("%19s", codigo1);

    printf("Nome da Cidade: ");
    scanf("%19s", cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosT1);

    densidade1 = (area1 > 0) ? (float)populacao1 / area1 : 0.0f;
    pibpc1     = (populacao1 > 0) ? pib1 / (float)populacao1 : 0.0f;

    // ===== Cadastro Carta 2 =====
    printf("\nCadastro da Carta 2\n");

    printf("Estado: ");
    scanf("%19s", estado2);

    printf("Codigo: ");
    scanf("%19s", codigo2);

    printf("Nome da Cidade: ");
    scanf("%19s", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosT2);

    densidade2 = (area2 > 0) ? (float)populacao2 / area2 : 0.0f;
    pibpc2     = (populacao2 > 0) ? pib2 / (float)populacao2 : 0.0f;

    // ===== Menu =====
    printf("\n*** Escolha o atributo para a competição ***\n");
    printf("1. População (maior vence)\n");
    printf("2. Área (maior vence)\n");
    printf("3. PIB per capita (maior vence)\n");
    printf("4. Número de pontos turísticos (maior vence)\n");
    printf("5. Densidade Demográfica (menor vence)\n");

    printf("Qual a sua escolha? ");
    scanf("%d", &escolha_atributo);

    // ===== Resultado estilo “Super Trunfo” =====
    printf("\n======== CARTAS ========\n");
    printf("Carta 1: %s (%s) - Codigo: %s\n", cidade1, estado1, codigo1);
    printf("Carta 2: %s (%s) - Codigo: %s\n", cidade2, estado2, codigo2);

    printf("\n-------- Comparando --------\n");

    switch (escolha_atributo) {

        case 1:
            printf("Atributo: População\n");
            printf("Carta 1 (%s): %lu\n", cidade1, populacao1);
            printf("Carta 2 (%s): %lu\n", cidade2, populacao2);

            if (populacao1 > populacao2) printf("Resultado: Carta 1 venceu!\n");
            else if (populacao1 < populacao2) printf("Resultado: Carta 2 venceu!\n");
            else printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("Carta 1 (%s): %.2f\n", cidade1, area1);
            printf("Carta 2 (%s): %.2f\n", cidade2, area2);

            if (area1 > area2) printf("Resultado: Carta 1 venceu!\n");
            else if (area1 < area2) printf("Resultado: Carta 2 venceu!\n");
            else printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB per capita\n");
            printf("Carta 1 (%s): %.6f\n", cidade1, pibpc1);
            printf("Carta 2 (%s): %.6f\n", cidade2, pibpc2);

            if (pibpc1 > pibpc2) printf("Resultado: Carta 1 venceu!\n");
            else if (pibpc1 < pibpc2) printf("Resultado: Carta 2 venceu!\n");
            else printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1 (%s): %d\n", cidade1, pontosT1);
            printf("Carta 2 (%s): %d\n", cidade2, pontosT2);

            if (pontosT1 > pontosT2) printf("Resultado: Carta 1 venceu!\n");
            else if (pontosT1 < pontosT2) printf("Resultado: Carta 2 venceu!\n");
            else printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demográfica (menor vence)\n");
            printf("Carta 1 (%s): %.2f\n", cidade1, densidade1);
            printf("Carta 2 (%s): %.2f\n", cidade2, densidade2);

            if (densidade1 < densidade2) printf("Resultado: Carta 1 venceu!\n");
            else if (densidade1 > densidade2) printf("Resultado: Carta 2 venceu!\n");
            else printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}