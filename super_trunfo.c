#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
    double superPoder; // Alterado para double
} Carta;

// Funções auxiliares para comparação com precisão
int compararMaior(double a, double b) {
    return (a > b) ? 1 : 0;
}

int compararMenor(double a, double b) {
    return (a < b) ? 1 : 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerCarta(Carta *c) {
    printf("Estado: ");
    scanf("%2s", c->estado);

    printf("Código: ");
    scanf("%3s", c->codigo);

    limparBuffer();
    printf("Nome da cidade: "); // Movido para ficar logo após estado e código
    fgets(c->nomeCidade, sizeof(c->nomeCidade), stdin);
    c->nomeCidade[strcspn(c->nomeCidade, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &c->populacao);

    printf("Área: ");
    scanf("%lf", &c->area);

    printf("PIB: ");
    scanf("%lf", &c->pib);

    printf("Pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    printf("Densidade populacional: ");
    scanf("%lf", &c->densidadePopulacional);

    printf("PIB per capita: ");
    scanf("%lf", &c->pibPerCapita);

    // Cálculo atualizado do Super Poder
    c->superPoder =
        (double)c->populacao +
        c->area +
        (double)c->pib +
        c->pontosTuristicos +
        c->densidadePopulacional +
        c->pibPerCapita +
        (1.0 / c->densidadePopulacional);
}

void exibirCarta(Carta c) {
    printf("\nEstado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2lf\n", c.area);
    printf("PIB: %.2lf\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2lf\n", c.densidadePopulacional);
    printf("PIB per capita: %.2lf\n", c.pibPerCapita);
    printf("SUPER PODER: %.2lf\n", c.superPoder); // %lf para double
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da primeira carta:\n");
    lerCarta(&carta1);

    printf("\nDigite os dados da segunda carta:\n");
    lerCarta(&carta2);

    printf("\n--- Carta 1 ---");
    exibirCarta(carta1);
    printf("\n--- Carta 2 ---");
    exibirCarta(carta2);

    printf("\nComparações:\n");
    printf("População (C1 > C2): %d\n", compararMaior((double)carta1.populacao, (double)carta2.populacao));
    printf("Super Poder (C1 > C2): %d\n", compararMaior(carta1.superPoder, carta2.superPoder));

    return 0;
}
