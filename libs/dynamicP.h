#include "aux.h"
#include <stdio.h>

// Function that generates the tables for Dynamic Programming
void calculateNumberCoins(int change, int num_coins, int *coin_types, bool *permutations, int *coins)
{
    // Initialize first row of the matrices to false and zero
    for (int i = 0; i < num_coins; i++)
    {
        *((permutations + i * change) + 0) = false;
        *((coins + i * change) + 0) = 0;
    }

    change += 1;

    for (int i = 0; i < num_coins; i++)
    {
        for (int j = 0; j < change; j++)
        {
            if (i == 0 && j < coin_types[i])
            {
                *((coins + i * change) + j) = 0;
                *((permutations + i * change) + j) = false;
            }
            else if (i == 0)
            {
                *((coins + i * change) + j) = 1 + *((coins + i * change) + (j - coin_types[0]));
                *((permutations + i * change) + j) = true;
            }
            else if (j < coin_types[i])
            {
                *((coins + i * change) + j) = *((coins + (i - 1) * change) + j);
                *((permutations + i * change) + j) = false;
            }
            else
            {
                *((coins + i * change) + j) = min(*((coins + (i - 1) * change) + j), 1 + *((coins + i * change) + (j - coin_types[i])));
                *((permutations + i * change) + j) = (*((coins + i * change) + j) != *((coins + (i - 1) * change) + j));
            }
        }
    }
     
    for (int i = 0; i < num_coins; i++)
    {
        for (int j = 0; j < change; j++)
        printf("%d, ", *((coins + i * change) + j));
        printf("\n");
    }
}

// Function that given the tables of Dynamic Programming finds the most efficient way to give change back
void calculateCoins(int change, int num_coins, int *coin_types, bool *permutations, int *coins, int *solution)
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