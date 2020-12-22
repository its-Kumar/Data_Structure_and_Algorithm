/*
Author:         Kumar Shanu
Problem:        Find out the total number of ways you can make the change of
                        given amount using given coins.
Problem link:   https://leetcode.com/problems/coin-change-2/

Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

int findchange(int coins[], int n, int amount)
{
    if (amount == 0)
        return 1;
    if (n == 0)
        return 0;

    int arr[n][amount + 1];

    memset(arr, 0, sizeof(arr));

    for (int j = 0; j <= amount; j++)
        arr[0][j] = (int)(j % coins[0] == 0);

    for (int i = 1; i < n; i++)
    {
        arr[i][0] = 1;
        for (int j = 0; j <= amount; j++)
        {
            if (coins[i] > j)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = arr[i - 1][j] + arr[i][j - coins[i]];
        }
    }

    return arr[n - 1][amount];
}

int main()
{
    int coins[] = {2, 3, 5, 10}, w = 15;

    printf("%d\n", findchange(coins, 4, w));

    return 0;
}
