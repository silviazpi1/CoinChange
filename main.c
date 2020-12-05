#include <stdio.h>
#include "aux.h"


int main(int argc, char *argv[]) {
    int number_coins;

    printf("\e[1;1H\e[2J"); // Limpiar pantalla de la consola
    printf(ANSI_COLOR_MAGENTA "PROGRAMACION DINAMICA: "ANSI_COLOR_RESET"PROBLEMA DEL CAMBIO\n\n");

    // Crear vector de monedas existentes
    printf("Introduzca el numero de monedas de diferentes existentes: ");
    scanf("%d", &number_coins);
    int coins_vector[number_coins];
    printf("\n");
    
    // Rellenar vector de monedas existentes
    printf("Introduzca de uno en uno el valor de las monedas existentes:\n");
    for(int i = 0; i<number_coins; i++){
        scanf("%d", &coins_vector[i]);
    }
    printf("\n");

    QuickSort(coins_vector, 0, number_coins-1);
    printf("Vector obtenido");
    for(int i = 0; i<number_coins; i++){
        printf("%d", coins_vector[i]);
    }

    return 0; 
}