/**
 *  Author:         Kumar Shanu
 *  Problem:        0/1 Knapsack problem
 *
 *  Dynamic Programming
*/
#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int findMaxProfit(int weights[], int n, int profits[], int m, int capacity)
{
    /*!
    0/1 Knapsack problem solution using dynamic programming

        Find out the maximum profit.Args :

        weights(list[int]) : array of weights available
        profits(list[int]) : array of profits available
        capacity(int) : maximum capacity of knapsack

        Returns :
        int : maximum profit
    */
    if (n != m)
    {
        printf("Please provide correct values for profits and weights");
        return -1;
    }
    int dp[n + 1][capacity + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= capacity; j++)
            if (j >= weights[i - 1])
                dp[i][j] = max(dp[i - 1][j], (profits[i - 1] + dp[i - 1][j - weights[i - 1]]));
            else
                dp[i][j] = dp[i - 1][j];
    }

    return dp[n][capacity];
}

int main()
{
    int weights[] = {3, 4, 6, 5};
    int profits[] = {2, 3, 1, 4};
    int w = 8;
    printf("Maximum profit is: %d\n", findMaxProfit(weights, 4, profits, 4, w));

    return 0;
}
