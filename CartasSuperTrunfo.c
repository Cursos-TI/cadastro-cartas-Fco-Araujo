#include <stdio.h>

int main(){

    // Carta 1
    char estado1[20], codigo1[20], cidade1[20];
    int pontosT1;
    float area1, pib1, densidadetotal1,pibtotal1;
    unsigned long int populacao1;

    // Carta 2
    char estado2[20], codigo2[20], cidade2[20];
    int pontosT2;
    float area2, pib2, densidadetotal2,pibtotal2;
    unsigned long int populacao2;

    // Carta 1
    printf("Cadastro da Carta 1\n");

    printf("Estado: ");
    scanf("%s", estado1);

    printf("Codigo: ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf("%s", cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosT1);

    // Calcula densidade depois de ler os dados
    densidadetotal1 = (float)populacao1 / area1;
    pibtotal1 = (float) pib1/populacao1;


    // Carta 2
    printf("\nCadastro da Carta 2\n");

    printf("Estado: ");
    scanf("%s", estado2);

    printf("Codigo: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf("%s", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosT2);

    // Calcula densidade depois de ler os dados
    densidadetotal2 = (float)populacao2 / area2;
    pibtotal2 = (float) pib2/populacao2;
  

    // Exibindo
    /*printf("\n\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %uld\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosT1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadetotal1);
    printf("PIB per Capita: %.2f Reais\n", pibtotal1);
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %uld\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosT2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadetotal2);
    printf("PIB per Capita: %.2f Reais\n", pibtotal2);*/

    float superpoder1 = (float)populacao1 + area1 + pib1 + (float)pontosT1 + densidadetotal1;
    float superpoder2 = (float)populacao2 + area2 + pib2 + (float)pontosT2 + densidadetotal2;
    

    //comparando as cartas
    printf("------Comparação de cartas----- \n \n");

    printf("Populacao: carta: %d venceu\n", populacao1 > populacao2);
    printf("Área: carta: %d venceu\n", area1 > area2);
    printf("PIB: Carta: %d venceu\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta %d venceu\n", pontosT1 > pontosT2);
    printf("Densidade: Populacional: Carta %d venceu\n", densidadetotal1 < densidadetotal2);
    printf("PIB per Capita: Carta %d venceu\n", pibtotal1 > pibtotal2);
    printf("Super Poder: Carta %d venceu\n", superpoder1 > superpoder2);
    printf("JOGO FINALIZADO");


    return 0;
}