/*
Author: Kumar Shanu
Problem:        Find out the minimum number of coins to make the change of
                        given amount using given coins.
Problem link:   https://leetcode.com/problems/coin-change/

Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int findMinimumCoins(int coins[], int n, int amount)
{
    int arr[n][amount + 1];

    memset(arr, 9999, sizeof(arr));

    for (int j = 0; j <= amount; j++)
    {
        if (j % coins[0] == 0)
            arr[0][j] = j / coins[0];
        else
            arr[0][j] = 9999;
    }

    for (int i = 1; i < n; i++)
    {
        arr[i][0] = 0;
        for (int j = 0; j <= amount; j++)
        {
            if (coins[i] > j)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = min(arr[i - 1][j], 1 + arr[i][j - coins[i]]);
        }
    }

    return arr[n - 1][amount];
}

int main()
{
    int coins[] = {1, 5, 6, 9}, w = 11;

    printf("%d\n", findMinimumCoins(coins, 4, w));

    return 0;
}
