#include <stdio.h>
#include <string.h>

// Funções auxiliares para comparação
int compararMaior(float a, float b) {
    return (a > b) ? 1 : 0;
}

int compararMenor(float a, float b) {
    return (a < b) ? 1 : 0;
}


int main(){
    char estado;                        // dados da carta 1
    char codigodacarta [20];
    char nomedacidade [49];
    unsigned long int populacao;
    float area;
    float pib;
    int numerosdept;      // numerosdept = numeros de ponto turísticos
    float densidadepopulacional;
    float pibpercapta;
    float superpoder;

    // dados da carta 2
    
    char estado2;                     
    char codigodacarta2 [20];
    char nomedacidade2 [49];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int numerosdept2;
    float densidadepopulacional2;
    float pibpercapta2;     
    float superpoder2;



    // Carta 1 
    printf("Carta 1: \n");

    printf("Estado: \n");
    scanf(" %c", &estado);
    getchar(); //para limpar o erro de \n

    printf("Codigo da carta: \n");
    scanf("%s", codigodacarta);

    printf("Nome da cidade: \n");
    scanf(" %49[^\n]", nomedacidade);

    printf("Digite a população: \n");
    scanf("%lu", &populacao);

    printf("Digite a área: \n");
    scanf(" %f", &area);

    printf("Digite o PIB: \n");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &numerosdept);


    printf("\n");

    // Carta 2
    printf("Carta 2: \n");

    printf("Estado: \n");
    scanf(" %c", &estado2);
    getchar(); //para limpar o erro de \n

    printf("Codigo da carta: \n");
    scanf("%s", codigodacarta2);

    printf("Nome da cidade: \n");
    scanf(" %49[^\n]", nomedacidade2);

    printf("Digite a população: \n");
    scanf("%lu", &populacao2);

    printf("Digite a área: \n");
    scanf("%f", &area2);

    printf("Digite o PIB: \n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &numerosdept2);


    // Calculos do PIB e Densidade

    // Calculos da Carta 1 com prevenção de divisão por zero
if (area > 0.0f) {
    densidadepopulacional = (float)populacao / area;
} else {
    densidadepopulacional = 0.0f;
    printf("Aviso: Área da Carta 1 é zero. Densidade populacional não calculada.\n");
}

if (populacao > 0) {
    pibpercapta = (pib * 1000000000.0f) / populacao;
} else {
    pibpercapta = 0.0f;
    printf("Aviso: População da Carta 1 é zero. PIB per capita não calculado.\n");
}

if (densidadepopulacional > 0.0f) {
    superpoder = (float)populacao + area + pib + numerosdept + (1.0f / densidadepopulacional);
} else {
    superpoder = (float)populacao + area + pib + numerosdept;
    printf("Aviso: Densidade populacional da Carta 1 é zero. Super poder não inclui o fator inverso.\n");
}

// Calculos da Carta 2 com prevenção de divisão por zero
if (area2 > 0.0f) {
    densidadepopulacional2 = (float)populacao2 / area2;
} else {
    densidadepopulacional2 = 0.0f;
    printf("Aviso: Área da Carta 2 é zero. Densidade populacional não calculada.\n");
}

if (populacao2 > 0) {
    pibpercapta2 = (pib2 * 1000000000.0f) / populacao2;
} else {
    pibpercapta2 = 0.0f;
    printf("Aviso: População da Carta 2 é zero. PIB per capita não calculado.\n");
}

if (densidadepopulacional2 > 0.0f) {
    superpoder2 = (float)populacao2 + area2 + pib2 + numerosdept2 + (1.0f / densidadepopulacional2);
} else {
    superpoder2 = (float)populacao2 + area2 + pib2 + numerosdept2;
    printf("Aviso: Densidade populacional da Carta 2 é zero. Super poder não inclui o fator inverso.\n");
}


    // Saída de dados da carta 1

    printf("Carta 1: \n");
    printf("Estado: %c \n", estado);
    printf("Código da carta: %s \n", codigodacarta);
    printf("Nome da cidade: %s \n", nomedacidade);
    printf("População: %lu habitantes\n", populacao);
    printf("Área: %.2f km² \n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de pontos turísticos: %d \n", numerosdept);
    printf("Densidade Populacional: %.2f hab/km² \n", densidadepopulacional);
    printf("PIB per capita: %.2f reais \n", pibpercapta);

    printf("\nSUPER PODER: %.2f\n", superpoder);

    printf("\n");     
    
    // Saída de dados da carta 2

    printf("Carta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código da carta: %s \n", codigodacarta2);
    printf("Nome da cidade: %s \n", nomedacidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turísticos: %d \n", numerosdept2);
    printf("Densidade Populacional: %.2f hab/km² \n", densidadepopulacional2);
    printf("PIB per capita: %.2f reais \n", pibpercapta2);

    printf("\nSUPER PODER: %.2f\n", superpoder2);

    // comparação das cartas
    printf("\n--- Comparação de Cartas ---\n");
    printf("População: %d\n", compararMaior(populacao, populacao2));
    printf("Área: %d\n", compararMaior(area, area2));
    printf("PIB: %d\n", compararMaior(pib, pib2));
    printf("Pontos Turísticos: %d\n", compararMaior(numerosdept, numerosdept2));
    printf("Densidade Populacional: %d\n", compararMenor(densidadepopulacional, densidadepopulacional2));
    printf("PIB per capita: %d\n", compararMaior(pibpercapta, pibpercapta2));
    printf("Super Poder: %d\n", compararMaior(superpoder, superpoder2));



    return 0;



}