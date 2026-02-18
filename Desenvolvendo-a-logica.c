
//aqui eu vou entregar o exercicio do tema 3 (desenvolvendo a logica)
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

    printf("\n");

    printf("Comparacao de cartas (Atributo População) \n");
    printf("Carta 1: %s - (%s) : %lu \n",cidade1,estado1,populacao1 );
    printf("Carta 2: %s - (%s) : %lu \n",cidade2,estado2,populacao2);


    printf("\n--------Resultado da rodada--------\n");

    if (populacao1 > populacao2){
        printf("Carta 1 %s venceu!", cidade1);
    }
    else{
        printf("Carta 2 %s venceu!", cidade2);
    }

    return 0;
}
