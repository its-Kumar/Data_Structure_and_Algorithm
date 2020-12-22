"""
Author:         Kumar Shanu
Problem:        Find out the minimum number of coins to make the change of
                        given amount using given coins.
Problem link:   https://leetcode.com/problems/coin-change/

Dynamic Programming
"""
from math import inf


def findMinimumCoins(coins: "list[int]", change: int) -> int:
    n, m = len(coins), change+1
    coins.sort()
    arr = [[inf for i in range(m)] for j in range(n)]

    if n == 0:
        return 0

    for j in range(m):
        arr[0][j] = j//coins[0] if j % coins[0] == 0 else inf

    for i in range(1, n):
        arr[i][0] = 0
        for j in range(m):

            if coins[i] > j:
                arr[i][j] = arr[i-1][j]
            else:
                arr[i][j] = min(arr[i-1][j], 1+arr[i][j-coins[i]])

    print(arr)
    return arr[-1][-1] if arr[-1][-1] != inf else -1


if __name__ == "__main__":
    coins = [1, 5, 6, 9]
    w = 11
    print(findMinimumCoins(coins, w))
