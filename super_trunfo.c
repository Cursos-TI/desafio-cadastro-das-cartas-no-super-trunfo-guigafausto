#include <stdio.h>
#include <string.h>

#define TAM_CODIGO 4
#define MAX_CIDADE 50
#define ESCALA_BILHOES 1000000000.0f

// Funções auxiliares para comparação
int compararMaior(float a, float b) {
    return (a > b) ? 1 : 0;
}

int compararMenor(float a, float b) {
    return (a < b) ? 1 : 0;
}

// Struct para armazenar os dados
struct Carta {
    char estado;
    char codigo[TAM_CODIGO]; // até 3 caracteres + \0
    char cidade[MAX_CIDADE];
    unsigned long int populacao; // para grandes valores
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
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
    scanf("%3s", c->codigo); // limite de 3 caracteres
    limparBuffer();

    printf("Digite a população: ");
    scanf("%lu", &c->populacao);
    limparBuffer();

    printf("Digite a área: ");
    scanf("%f", &c->area);
    limparBuffer();

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &c->pib);
    limparBuffer();

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
    limparBuffer();

    printf("Nome da cidade: ");
    fgets(c->cidade, sizeof(c->cidade), stdin);
    c->cidade[strcspn(c->cidade, "\n")] = '\0'; // remove \n final

    // Cálculos com prevenção de divisão por zero
    if (c->area > 0.0f) {
        c->densidadePopulacional = (float)c->populacao / c->area;
    } else {
        c->densidadePopulacional = 0.0f;
        printf("Aviso: Área é zero. Densidade populacional não calculada.\n");
    }

    if (c->populacao > 0) {
        c->pibPerCapita = (c->pib * ESCALA_BILHOES) / c->populacao;
    } else {
        c->pibPerCapita = 0.0f;
        printf("Aviso: População é zero. PIB per capita não calculado.\n");
    }

    if (c->densidadePopulacional > 0.0f) {
        c->superPoder = (float)c->populacao + c->area + (float)c->pib + c->pontosTuristicos
                      + (1.0f / c->densidadePopulacional);
    } else {
        c->superPoder = (float)c->populacao + c->area + (float)c->pib + c->pontosTuristicos;
    }
}

// Função para exibir dados da carta
void exibirCarta(struct Carta c) {
    printf("Estado: %c\n", c.estado);
    printf("Código da carta: %s\n", c.codigo);
    printf("Nome da cidade: %s\n", c.cidade);
    printf("População: %lu habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f reais\n", c.pibPerCapita);
    printf("SUPER PODER: %.2f\n", c.superPoder);
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
    printf("População: %d\n", compararMaior(carta1.populacao, carta2.populacao));
    printf("Área: %d\n", compararMaior(carta1.area, carta2.area));
    printf("PIB: %d\n", compararMaior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: %d\n", compararMaior(carta1.pontosTuristicos, carta2.pontosTuristicos));
    printf("Densidade Populacional: %d\n", compararMenor(carta1.densidadePopulacional, carta2.densidadePopulacional));
    printf("PIB per capita: %d\n", compararMaior(carta1.pibPerCapita, carta2.pibPerCapita));
    printf("Super Poder: %d\n", compararMaior(carta1.superPoder, carta2.superPoder));

    return 0;
}
