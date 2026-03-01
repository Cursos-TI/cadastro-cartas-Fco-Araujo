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

    int attr1, attr2;

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

    // ===== Menu 1 (primeiro atributo) =====
    printf("\n*** Escolha o 1º atributo para a competição ***\n");
    printf("1. População (maior vence)\n");
    printf("2. Área (maior vence)\n");
    printf("3. PIB per capita (maior vence)\n");
    printf("4. Número de pontos turísticos (maior vence)\n");
    printf("5. Densidade Demográfica (menor vence)\n");

    printf("Qual a sua escolha? ");
    scanf("%d", &attr1);

    if (attr1 < 1 || attr1 > 5) {
        printf("Opção inválida!\n");
        return 0;
    }

    // ===== Menu 2 (dinâmico) =====
    printf("\n*** Escolha o 2º atributo (diferente do 1º) ***\n");

    // Aqui o menu é dinâmico: não mostra o attr1
    for (int op = 1; op <= 5; op++) {
        if (op == attr1) continue;

        switch (op) {
            case 1: printf("1. População (maior vence)\n"); break;
            case 2: printf("2. Área (maior vence)\n"); break;
            case 3: printf("3. PIB per capita (maior vence)\n"); break;
            case 4: printf("4. Número de pontos turísticos (maior vence)\n"); break;
            case 5: printf("5. Densidade Demográfica (menor vence)\n"); break;
        }
    }

    printf("Qual a sua escolha? ");
    scanf("%d", &attr2);

    // validações
    if (attr2 < 1 || attr2 > 5) {
        printf("Opção inválida!\n");
        return 0;
    }
    if (attr2 == attr1) {
        printf("Você não pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    // ===== Funções/variáveis de apoio (sem criar funções pra manter seu padrão) =====
    float v1a = 0.0f, v2a = 0.0f;   // valores do atributo 1 (carta 1 e 2)
    float v1b = 0.0f, v2b = 0.0f;   // valores do atributo 2 (carta 1 e 2)

    const char *nomeA = "";
    const char *nomeB = "";

    // Para somar com regra consistente (maior soma vence):
    // atributos normais: score = valor
    // densidade: score = 1/densidade (menor densidade -> maior score)
    float s1a = 0.0f, s2a = 0.0f;
    float s1b = 0.0f, s2b = 0.0f;

    // resultado individual: 1 carta1 vence, -1 carta2 vence, 0 empate
    int rA = 0, rB = 0;

    // ===== Captura do atributo 1 =====
    switch (attr1) {
        case 1:
            nomeA = "População";
            v1a = (float)populacao1; v2a = (float)populacao2;
            s1a = v1a; s2a = v2a;
            rA = (v1a > v2a) ? 1 : (v1a < v2a) ? -1 : 0;
            break;

        case 2:
            nomeA = "Área";
            v1a = area1; v2a = area2;
            s1a = v1a; s2a = v2a;
            rA = (v1a > v2a) ? 1 : (v1a < v2a) ? -1 : 0;
            break;

        case 3:
            nomeA = "PIB per capita";
            v1a = pibpc1; v2a = pibpc2;
            s1a = v1a; s2a = v2a;
            rA = (v1a > v2a) ? 1 : (v1a < v2a) ? -1 : 0;
            break;

        case 4:
            nomeA = "Pontos Turísticos";
            v1a = (float)pontosT1; v2a = (float)pontosT2;
            s1a = v1a; s2a = v2a;
            rA = (v1a > v2a) ? 1 : (v1a < v2a) ? -1 : 0;
            break;

        case 5:
            nomeA = "Densidade Demográfica";
            v1a = densidade1; v2a = densidade2;

            // score invertido para somar (menor densidade -> maior score)
            s1a = (densidade1 > 0.0f) ? (1.0f / densidade1) : 0.0f;
            s2a = (densidade2 > 0.0f) ? (1.0f / densidade2) : 0.0f;

            // regra de comparação: menor vence
            rA = (v1a < v2a) ? 1 : (v1a > v2a) ? -1 : 0;
            break;
    }

    // ===== Captura do atributo 2 =====
    switch (attr2) {
        case 1:
            nomeB = "População";
            v1b = (float)populacao1; v2b = (float)populacao2;
            s1b = v1b; s2b = v2b;
            rB = (v1b > v2b) ? 1 : (v1b < v2b) ? -1 : 0;
            break;

        case 2:
            nomeB = "Área";
            v1b = area1; v2b = area2;
            s1b = v1b; s2b = v2b;
            rB = (v1b > v2b) ? 1 : (v1b < v2b) ? -1 : 0;
            break;

        case 3:
            nomeB = "PIB per capita";
            v1b = pibpc1; v2b = pibpc2;
            s1b = v1b; s2b = v2b;
            rB = (v1b > v2b) ? 1 : (v1b < v2b) ? -1 : 0;
            break;

        case 4:
            nomeB = "Pontos Turísticos";
            v1b = (float)pontosT1; v2b = (float)pontosT2;
            s1b = v1b; s2b = v2b;
            rB = (v1b > v2b) ? 1 : (v1b < v2b) ? -1 : 0;
            break;

        case 5:
            nomeB = "Densidade Demográfica";
            v1b = densidade1; v2b = densidade2;

            s1b = (densidade1 > 0.0f) ? (1.0f / densidade1) : 0.0f;
            s2b = (densidade2 > 0.0f) ? (1.0f / densidade2) : 0.0f;

            rB = (v1b < v2b) ? 1 : (v1b > v2b) ? -1 : 0;
            break;
    }

    // ===== Soma dos atributos (usando scores) =====
    float soma1 = s1a + s1b;
    float soma2 = s2a + s2b;

    // ===== Impressão clara do resultado =====
    printf("\n======== CARTAS ========\n");
    printf("Carta 1: %s (%s) - Codigo: %s\n", cidade1, estado1, codigo1);
    printf("Carta 2: %s (%s) - Codigo: %s\n", cidade2, estado2, codigo2);

    printf("\n======== ATRIBUTOS ESCOLHIDOS ========\n");
    printf("1º Atributo: %s\n", nomeA);
    printf("2º Atributo: %s\n", nomeB);

    printf("\n======== VALORES ========\n");
    printf("%s\n", nomeA);
    printf("  Carta 1 (%s): %.6f\n", cidade1, v1a);
    printf("  Carta 2 (%s): %.6f\n", cidade2, v2a);

    if (rA == 1) printf("  Vencedor do atributo: Carta 1\n");
    else if (rA == -1) printf("  Vencedor do atributo: Carta 2\n");
    else printf("  Vencedor do atributo: Empate\n");

    printf("\n%s\n", nomeB);
    printf("  Carta 1 (%s): %.6f\n", cidade1, v1b);
    printf("  Carta 2 (%s): %.6f\n", cidade2, v2b);

    if (rB == 1) printf("  Vencedor do atributo: Carta 1\n");
    else if (rB == -1) printf("  Vencedor do atributo: Carta 2\n");
    else printf("  Vencedor do atributo: Empate\n");

    printf("\n======== SOMA DOS ATRIBUTOS (para vencer a rodada) ========\n");
    printf("Soma Carta 1 (%s): %.6f\n", cidade1, soma1);
    printf("Soma Carta 2 (%s): %.6f\n", cidade2, soma2);

    printf("\n======== RESULTADO FINAL ========\n");
    if (soma1 > soma2) printf("Resultado: Carta 1 venceu a rodada!\n");
    else if (soma1 < soma2) printf("Resultado: Carta 2 venceu a rodada!\n");
    else printf("Resultado: Empate!\n");

    return 0;
}