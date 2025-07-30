#include <stdio.h>

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
    char nomedacidade [20];
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
    char nomedacidade2 [20];
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
    scanf("%s", &codigodacarta);

    printf("Nome da cidade: \n");
    scanf(" %s", &nomedacidade);

    printf("Digite a população: \n");
    scanf("%d", &populacao);

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
    scanf("%s", &codigodacarta2);

    printf("Nome da cidade: \n");
    scanf(" %s", &nomedacidade2);

    printf("Digite a população: \n");
    scanf("%d", &populacao2);

    printf("Digite a área: \n");
    scanf("%f", &area2);

    printf("Digite o PIB: \n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &numerosdept2);


    // Calculos do PIB e Densidade

    densidadepopulacional = (float) populacao / area;
    pibpercapta = (float) pib / populacao;

    densidadepopulacional2 = (float) populacao2 / area2;
    pibpercapta2 = (float) pib2 / populacao2;

    // Calculos do super poder

    superpoder = (float) populacao + area + pib + numerosdept + pibpercapta + (1 / densidadepopulacional);
    superpoder2 = (float) populacao2 + area2 + pib2 + numerosdept2 + pibpercapta2 + (1 / densidadepopulacional2);


    // Saída de dados da carta 1

    printf("Carta 1: \n");
    printf("Estado: %c \n", estado);
    printf("Código da carta: %s \n", codigodacarta);
    printf("Nome da cidade: %s \n", nomedacidade);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.2f km² \n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de pontos turiríticos: %d \n", numerosdept);
    printf("Densidade Populaciona: %f hab/km² \n", densidadepopulacional);
    printf("PIB per capita: %f reais \n", pibpercapta);

    printf("\n");     
    
    // Saída de dados da carta 2

    printf("Carta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código da carta: %s \n", codigodacarta2);
    printf("Nome da cidade: %s \n", nomedacidade2);
    printf("População: %d habitantes\n", populacao2);
    printf("Área: %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turiríticos: %d \n", numerosdept2);
    printf("Densidade Populacional: %f hab/km² \n", densidadepopulacional2);
    printf("PIB per capita: %f reais \n", pibpercapta2);


    // comparação das cartas
    printf("\n--- Comparação de Cartas ---\n");
    printf("População: %s\n", (populacao > populacao2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Área: %s\n", (area > area2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("PIB: %s\n", (pib > pib2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Pontos Turísticos: %s\n", (numerosdept > numerosdept2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Densidade Populacional: %s\n", (densidadepopulacional < densidadepopulacional2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("PIB per capita: %s\n", (pibpercapta > pibpercapta2) ? "Carta 1 venceu" : "Carta 2 venceu");
    printf("Super Poder: %s\n", (superpoder > superpoder2) ? "Carta 1 venceu" : "Carta 2 venceu");



    return 0;



}