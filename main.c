#include "libs/dynamicP.h"

int main(int argc, char *argv[])
{
    int temp_num_coins, temp_change;

    printf("\e[1;1H\e[2J"); // Clear console
    printf(ANSI_COLOR_MAGENTA "DYNAMIC PROGRAMMING: " ANSI_COLOR_RESET "COIN CHANGE\n");

    // Get the change to give back
    printf("\nIntroduce the change to give back (less than 11, for the moment only integer values): ");
    scanf("%d", &temp_change);
    const int change = temp_change;

    // Create the vector with the different existing coins
    printf("\nIntroduce the number of different existing coins (less than 11): ");
    scanf("%d", &temp_num_coins);
    const int num_coins = temp_num_coins;
    float coin_types[num_coins];

    // Fill the vector with the values of the existing coins
    printf("\nIntroduce one by one the values of the different existing coins:\n");
    for (int i = 0; i < num_coins; i++)
        scanf("%f", &coin_types[i]);

    // Sort the vector
    QuickSort(coin_types, 0, num_coins - 1);

    // Generate the tables (Dynamic Programming)
    int coins[n][c];
    bool permutations[n][c];
    //calculateNumberCoins(change);

    // Calculate the coins to give back (using the generated tables)
    int solution[num_coins];
    calculateCoins(change, num_coins, coin_types, permutations, coins, solution);

    // Give change back
    printf("\nThe most efficient way to give back %d is:\n", change);
    for(int i = 0; i<num_coins; i++)
        printf("%d coins of %f\n", solution[i], coin_types[i]);
    printf("\n");

    return 0;
}