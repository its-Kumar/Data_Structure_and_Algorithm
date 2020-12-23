"""
Author:         Kumar Shanu
Problem:        0/1 Knapsack problem

Dynamic Programming
"""


def findMaxProfit(weights: "list[int]", profits: "list[int]", capacity: "int") -> int:
    """0/1 Knapsack problem solution using dynamic programming

        Find out the maximum profit.
    Args:

        weights (list[int]): list/array of weights available
        profits (list[int]): list/ array of profits available
        capacity (int): maximum capacity of knapsack
    Returns:

        int: maximum profit
    """
    if len(weights) != len(profits):
        print("Please provide correct values for profits and weights")
        return -1

    n = len(weights)
    dp = [[0 for _ in range(capacity+1)] for _ in range(n+1)]

    for i in range(1, n+1):
        for j in range(1, capacity+1):
            if (j >= weights[i-1]):
                dp[i][j] = max(
                    dp[i-1][j], (profits[i-1] + dp[i-1][j-weights[i-1]]))
            else:
                dp[i][j] = dp[i-1][j]

    print(dp)
    return dp[-1][-1]


if __name__ == "__main__":
    weights = [3, 4, 6, 5]
    profits = [2, 3, 1, 4]
    w = 8
    print("Maximum profit is: ", findMaxProfit(weights, profits, w))
