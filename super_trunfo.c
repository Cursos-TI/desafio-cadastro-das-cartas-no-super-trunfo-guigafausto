#include <stdio.h>
#include <string.h>

#define TAM_CODIGO 4
#define MAX_CIDADE 50
#define ESCALA_BILHOES 1000000000.0

// Funções auxiliares para comparação
int compararMaior(double a, double b) {
    return (a > b) ? 1 : 0;
}

int compararMenor(double a, double b) {
    return (a < b) ? 1 : 0;
}

// Struct para armazenar os dados
struct Carta {
    char estado;
    char codigo[TAM_CODIGO];
    char cidade[MAX_CIDADE];
    unsigned long int populacao;
    double area;
    double pib; // em bilhões
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
    double superPoder; // agora double
};

// Função para limpar buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler dados da carta
void lerCarta(struct Carta *c) {
    printf("Estado: ");
    scanf(" %c", &c->estado);
    limparBuffer();

    printf("Código da carta: ");
    scanf("%3s", c->codigo);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(c->cidade, sizeof(c->cidade), stdin);
    c->cidade[strcspn(c->cidade, "\n")] = '\0';

    printf("Digite a população: ");
    scanf("%lu", &c->populacao);
    limparBuffer();

    printf("Digite a área: ");
    scanf("%lf", &c->area);
    limparBuffer();

    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &c->pib);
    limparBuffer();

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
    limparBuffer();

    // Cálculos com prevenção de divisão por zero
    if (c->area > 0.0) {
        c->densidadePopulacional = (double)c->populacao / c->area;
    } else {
        c->densidadePopulacional = 0.0;
        printf("Aviso: Área é zero. Densidade populacional não calculada.\n");
    }

    if (c->populacao > 0) {
        c->pibPerCapita = (c->pib * ESCALA_BILHOES) / (double)c->populacao;
    } else {
        c->pibPerCapita = 0.0;
        printf("Aviso: População é zero. PIB per capita não calculado.\n");
    }

    // Agora inclui TODOS os atributos numéricos + inverso da densidade
    if (c->densidadePopulacional > 0.0) {
        c->superPoder = (double)c->populacao 
                      + c->area 
                      + c->pib 
                      + c->pontosTuristicos
                      + c->densidadePopulacional
                      + c->pibPerCapita
                      + (1.0 / c->densidadePopulacional);
    } else {
        c->superPoder = (double)c->populacao 
                      + c->area 
                      + c->pib 
                      + c->pontosTuristicos
                      + c->densidadePopulacional
                      + c->pibPerCapita;
    }
}

// Função para exibir dados da carta
void exibirCarta(struct Carta c) {
    printf("Estado: %c\n", c.estado);
    printf("Código da carta: %s\n", c.codigo);
    printf("Nome da cidade: %s\n", c.cidade);
    printf("População: %lu habitantes\n", c.populacao);
    printf("Área: %.2lf km²\n", c.area);
    printf("PIB: %.2lf bilhões de reais\n", c.pib);
    printf("Número de pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2lf reais\n", c.pibPerCapita);
    printf("SUPER PODER: %.2lf\n", c.superPoder);
}

int main() {
    struct Carta carta1, carta2;

    printf("=== Carta 1 ===\n");
    lerCarta(&carta1);

    printf("\n=== Carta 2 ===\n");
    lerCarta(&carta2);

    printf("\n--- Dados da Carta 1 ---\n");
    exibirCarta(carta1);

    printf("\n--- Dados da Carta 2 ---\n");
    exibirCarta(carta2);

    printf("\n--- Comparação de Cartas ---\n");
    printf("População: %d\n", compararMaior((double)carta1.populacao, (double)carta2.populacao));
    printf("Área: %d\n", compararMaior(carta1.area, carta2.area));
    printf("PIB: %d\n", compararMaior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: %d\n", compararMaior((double)carta1.pontosTuristicos, (double)carta2.pontosTuristicos));
    printf("Densidade Populacional: %d\n", compararMenor(carta1.densidadePopulacional, carta2.densidadePopulacional));
    printf("PIB per capita: %d\n", compararMaior(carta1.pibPerCapita, carta2.pibPerCapita));
    printf("Super Poder: %d\n", compararMaior(carta1.superPoder, carta2.superPoder));

    return 0;
}
