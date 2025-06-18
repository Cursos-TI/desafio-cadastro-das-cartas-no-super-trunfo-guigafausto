#include <stdio.h> 

int main(){
    
    // Informações da carta 1!

    char estado = 'B';
    char codigodacarta [20] = "B01";
    char nomedacidade [20] = "Bahia";
    int populacao = 14850513;
    float area = 567.295;
    float pib = 352.618;
    int numerodePT = 260;            // numerodePT - Pontos Turísticos

    // Informações da carta 2!

    char estado2 = 'C';
    char codigodacarta2 [20] = "B07";
    char nomedacidade2 [20] = "Rio de Janeiro";
    int populacao2 = 16000000;
    float area2 = 43.752;
    float pib2 = 753.83;
    int numerodePT2 = 90;            // numerodePT - Pontos Turísticos
    

    // Saída de dados da carta 1

    printf("Carta 1: \n");
    printf("Estado: %c \n", estado);
    printf("Código: %s \n", codigodacarta);
    printf("Nome da Cidade: %s \n", nomedacidade);
    printf("População: %d Habitantes \n", populacao);
    printf("Área: %.2f km² \n", area);
    printf("PIB: %.2f bilhões de reais \n", pib),
    printf("Numero de Pontos Turísticos: %d \n", numerodePT);

    printf("\n");

    // Saída de dados da carta 2

    printf("Carta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código: %s \n", codigodacarta2);
    printf("Nome da Cidade: %s \n", nomedacidade2);
    printf("População: %d Habitantes \n", populacao2);
    printf("Área: %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais \n", pib2),
    printf("Numero de Pontos Turísticos: %d \n", numerodePT2);


    return 0;

}
