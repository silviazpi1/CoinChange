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

    // Go through Coins and Permutations Matrices and fills them up
    for (int i = 0; i < num_coins; i++)
    {
        for (int j = 0; j < change; j++)
        {
            if (i == 0 && j < coin_types[i]) // If smallest kind of coin and quantity is smaller than its value
            {
                *((coins + i * change) + j) = 0;            // Set C[i, j] to 0
                *((permutations + i * change) + j) = false; // Set P[i, j] to False
            }
            else if (i == 0) // If smallest kind of coin and quantity is not smaller than its value, add one to coins
            {
                *((coins + i * change) + j) = 1 + *((coins + i * change) + (j - coin_types[0])); // C[i, j] = 1 + C[i,j-T[0]]
                *((permutations + i * change) + j) = true;                                       // Set P[i, j] to True
            }
            else if (j < coin_types[i]) // If the quantity is smaller than the value of the coin
            {
                *((coins + i * change) + j) = *((coins + (i - 1) * change) + j); // C[i, j] = C[i-1, j]
                *((permutations + i * change) + j) = false;                      // Set P[i, j] to False
            }
            else
            {
                *((coins + i * change) + j) = min(*((coins + (i - 1) * change) + j), 1 + *((coins + i * change) + (j - coin_types[i]))); // C[i, j] = min(C[i-1, j], 1+C[i, j-T[0]])
                *((permutations + i * change) + j) = (*((coins + i * change) + j) != *((coins + (i - 1) * change) + j));                 // Set P[i, j] to True if C[i, j] is different from C[i-1, j]
            }
        }
    }
}

// Function that given the tables of Dynamic Programming finds the most efficient way to give change back
void calculateCoins(int change, int num_coins, int *coin_types, bool *permutations, int *coins, int *solution)
{
    int i = num_coins, j = change - 1, index;

    // Initialize solution vector to zero
    for (index = 0; index < num_coins; index++)
        solution[index] = 0;

    // While there is more than one type of coin and there's still some change to give back
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

    // If there are is only one type of coin, add the number of coins needed to give back the change left
    if (i == 0)
        solution[0] = (*((coins + i * change) + j) + solution[0]);
}