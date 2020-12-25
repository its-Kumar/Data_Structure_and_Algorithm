/*
Author :    Kumar Shanu
Problem :   Subset of given sum is exists or not

Dynamic Programming
*/

#include <stdio.h>
#include <string.h>

int isSubset_sum(int arr[], int n, int target)
{ /**
    subset sum problem

    Find out if subset is exists in the given set with the given sum using dynamic programming
    Parameters:
    @param arr[]  = set/array of integers
    @param n = length of the arr
    @param target = target sum

    Returns:
    @return 0 if subset not found else  @return 1;
    */

    int dp[n + 1][target + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    return dp[n][target];
}

int main()
{
    int arr[] = {1, 2, 5, 9, 4};
    int sum = 18;
    if (isSubset_sum(arr, 5, sum))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
