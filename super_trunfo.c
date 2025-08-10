#include <stdio.h>
#include <string.h>

// ------------------- Struct -------------------
typedef struct {
    char estado[3];
    char codigo[4];
    char nome[50];
    unsigned long populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
    double superPoder;
} Carta;

// ------------------- Função para limpar buffer -------------------
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ------------------- Funções de comparação -------------------
int compararMaior(double a, double b) {
    return (a > b) ? 1 : 0;
}

int compararMenor(double a, double b) {
    return (a < b) ? 1 : 0;
}

// ------------------- Função para ler carta -------------------
#define ESCALA_BILHOES 1000000000.0

void lerCarta(Carta *c) {
    printf("Estado: ");
    scanf("%2s", c->estado);
    limparBuffer();

    printf("Código: ");
    scanf("%3s", c->codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &c->populacao);

    printf("Área (km²): ");
    scanf("%lf", &c->area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &c->pib);

    printf("Pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    // ----- Cálculos automáticos -----

    // Densidade Populacional
    if (c->area > 0.0) {
        c->densidadePopulacional = (double)c->populacao / c->area;
    } else {
        c->densidadePopulacional = 0.0;
        printf("Aviso: Área é zero. Densidade populacional não calculada.\n");
    }

    // PIB per Capita
    if (c->populacao > 0) {
        c->pibPerCapita = (c->pib * ESCALA_BILHOES) / (double)c->populacao;
    } else {
        c->pibPerCapita = 0.0;
        printf("Aviso: População é zero. PIB per capita não calculado.\n");
    }

    // Super Poder
    if (c->densidadePopulacional > 0.0) {
        c->superPoder = (double)c->populacao + c->area + c->pib +
                        c->pontosTuristicos + c->densidadePopulacional +
                        c->pibPerCapita + (1.0 / c->densidadePopulacional);
    } else {
        c->superPoder = (double)c->populacao + c->area + c->pib +
                        c->pontosTuristicos + c->pibPerCapita;
        printf("Aviso: Densidade populacional inválida. Super Poder calculado sem inverso.\n");
    }
}

// ------------------- Função para exibir carta -------------------
void exibirCarta(Carta c) {
    printf("\n----- CARTA -----\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nome);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2lf km²\n", c.area);
    printf("PIB: %.2lf bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2lf hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2lf\n", c.pibPerCapita);
    printf("SUPER PODER: %.2lf\n", c.superPoder);
}

// ------------------- Função principal -------------------
int main() {
    Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    lerCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    lerCarta(&carta2);

    // Exibição
    printf("\n--- CARTAS CADASTRADAS ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Comparações
    printf("\n--- COMPARAÇÕES (1 = SIM / 0 = NÃO) ---\n");
    printf("População (C1 > C2): %d\n", compararMaior((double)carta1.populacao, (double)carta2.populacao));
    printf("Área (C1 > C2): %d\n", compararMaior(carta1.area, carta2.area));
    printf("PIB (C1 > C2): %d\n", compararMaior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos (C1 > C2): %d\n", compararMaior((double)carta1.pontosTuristicos, (double)carta2.pontosTuristicos));
    printf("Densidade Populacional (C1 < C2): %d\n", compararMenor(carta1.densidadePopulacional, carta2.densidadePopulacional));
    printf("PIB per Capita (C1 > C2): %d\n", compararMaior(carta1.pibPerCapita, carta2.pibPerCapita));
    printf("Super Poder (C1 > C2): %d\n", compararMaior(carta1.superPoder, carta2.superPoder));

    return 0;
}
