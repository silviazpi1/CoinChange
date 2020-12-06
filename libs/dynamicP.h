#include "aux.h"
#include <stdio.h>

void calculateNumberCoins(int change, int num_coins, float *coin_types, bool *permutations, int *coins)
{
    // Initialize first row of the matrices to false and zero
    for (int i = 0; i < num_coins; i++)
    {
        *((permutations + i * change) + 0) = false;
        *((coins + i * change) + 0) = 0;
    }

    for (int i = 0; i < num_coins; i++)
    {
        for (int j = 0; j < change; j++)
        {
            if (i == 0 && j < coin_types[i])
            {
                *((coins + i * change) + j) = 0; //MAX(CARDINAL) ??????
                *((permutations + i * change) + j) = false;
            }
            else
            {
            }
        }
    }
}

void calculateCoins(int change, int num_coins, float *coin_types, bool *permutations, int *coins, int *solution)
{
    int i = num_coins, j = change, index;

    // Initialize solution vector to zero
    for (index = 0; index < num_coins; index++)
        solution[index] = 0;

    // While we haven't run out of coins and we still have some change to give back
    while (i != 0 && j != 0)
    {
        if (*((permutations + i * change) + j) == false) // If this coin is not used, skip it
            i--;
        else // Otherwise
        {
            solution[i] = solution[i] + 1; // Add one of these coins to the solution vector
            j = j - coin_types[i];         // Substract its value from the pending change
        }
    }

    // If there are is only one coin, add the number of first kind of coins needed to give back the change left
    if (i == 0)
        solution[0] = (*((coins + i * change) + j) + solution[0]);
}