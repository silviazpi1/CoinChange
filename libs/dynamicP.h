#include "aux.h"
#include <stdio.h>

const int n = 10, c = 10;

void calculateNumberCoins(int change)
{
}

void calculateCoins(int change, int num_coins, float *coin_types, bool permutations[n][c], int coins[n][c], int *solution)
{
    int i = num_coins, j = change, index;

    for (index = 0; index < num_coins; index++)
        solution[index] = 0;

    while (i != 0 && j != 0)
    {
        if (permutations[i][j] == false)
            i--;
        else
        {
            solution[i] = solution[i] + 1;
            j = j - coin_types[i];
        }
    }

    if (i == 0)
        solution[0] = coins[i][j] + solution[0];
}