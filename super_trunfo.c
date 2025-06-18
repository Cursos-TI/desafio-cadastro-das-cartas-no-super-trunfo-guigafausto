#include <stdio.h>

int main(){    
    int população;        // dados da carta 1
    float área;
    float pib;
    int numerosdept;      // numerosdept = numeros de ponto turísticos
    
    
    int população2;       // dados da carta 2
    float área2;
    float pib2;
    int numerosdept2;     // numerosdept = numeros de ponto turísticos

    // Entrada e saida de dados da carta 1 e 2

    printf("Carta 1: \n");
    printf("Digite a população: \n");
    scanf("%d", &população);

    printf("Digite a área: \n");
    scanf("%f", &área);

    printf("Digite o PIB: \n");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &numerosdept);

    printf("\n");

    printf("Carta 2: \n");
    printf("Digite a população: \n");
    scanf("%d", &população2);

    printf("Digite a área: \n");
    scanf("%f", &área2);

    printf("Digite o PIB: \n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: \n");
    scanf("%d", &numerosdept2);

    // Saída de dados da carta 1

    printf("Carta 1: \n");
    printf("População: %d habitantes\n", população);
    printf("Área: %.2f km² \n", área);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de pontos turiríticos: %d \n", numerosdept);

    printf("\n");     
    
    // Saída de dados da carta 2

    printf("Carta 2: \n");
    printf("População: %d habitantes\n", população2);
    printf("Área: %.2f km² \n", área2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turiríticos: %d \n", numerosdept2);


    return 0;

}
