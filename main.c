#include "libs/dynamicP.h"

int main(int argc, char *argv[])
{
    int num_coins, change;

    printf("\e[1;1H\e[2J"); // Clear console
    printf(ANSI_COLOR_MAGENTA "DYNAMIC PROGRAMMING: " ANSI_COLOR_RESET "COIN CHANGE\n");

    // Get the change to give back
    printf("\nIntroduce the change to give back: ");
    scanf("%d", &change);

    // Create the vector with the different existing coins
    printf("\nIntroduce the number of different existing coins: ");
    scanf("%d", &num_coins);
    int coin_types[num_coins];

    // Fill the vector with the values of the existing coins
    printf("\nIntroduce one by one the values of the different existing coins:\n");
    for (int i = 0; i < num_coins; i++)
        scanf("%d", &coin_types[i]);

    // Sort the vector
    QuickSort(coin_types, 0, num_coins - 1);

    if (coin_types[0] > change) // If the smallest coin is bigger than the change, no change can be given
        printf("The change cannot be given back, the smallest coin is bigger than the change\n");
    else // Otherwise
    {
        // Generate the tables (Dynamic Programming)
        int coins[num_coins][change+1];
        bool permutations[num_coins][change+1];
        calculateNumberCoins(change, num_coins, coin_types, (bool *)permutations, (int *)coins);

        // Calculate the coins to give back (using the generated tables)
        int solution[num_coins];
        calculateCoins(change, num_coins, coin_types, (bool *)permutations, (int *)coins, solution);

        // Give change back
        printf("\nThe most efficient way to give back %d is:\n", change);
        for (int i = 0; i < num_coins; i++)
            printf("%d coins of %d\n", solution[i], coin_types[i]);
        printf("\n");
    }

    printf(ANSI_COLOR_MAGENTA "END OF PROGRAM" ANSI_COLOR_RESET "\n");

    return 0;
}