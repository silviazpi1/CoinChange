#include "libs/pdinamica.h"


int main(int argc, char *argv[]) {
    int number_coins, change;

    printf("\e[1;1H\e[2J"); // Limpiar pantalla de la consola
    printf(ANSI_COLOR_MAGENTA "PROGRAMACION DINAMICA: "ANSI_COLOR_RESET"PROBLEMA DEL CAMBIO\n");

    // Obtener el cambio que se desea devolver
    printf("\nIntroduzca el cambio a devolver: ");
    scanf("%d", &change);
    
    // Crear vector de tipos de monedas existentes
    printf("\nIntroduzca el numero de monedas de diferentes existentes: ");
    scanf("%d", &number_coins);
    int coins_vector[number_coins];
    
    // Rellenar vector de tipos de monedas existentes
    printf("\nIntroduzca de uno en uno el valor de las monedas existentes:\n");
    for(int i = 0; i<number_coins; i++)
        scanf("%d", &coins_vector[i]);

    // Ordenar el vector recibido
    QuickSort(coins_vector, 0, number_coins-1);

    // Generacion de las tablas para la programacion dinamica
    int coins[number_coins][change];
    int permutations[number_coins][change];
    calculoNumeroMonedas();

    // Calculo del cambio necesario (buscando en las tablas generadas)
    calculoMonedas();

    return 0; 
}