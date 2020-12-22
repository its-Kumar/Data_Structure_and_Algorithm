"""
Author:         Kumar Shanu
Problem:        Find out the total number of ways you can make the change of
                        given amount using given coins.
Problem link:   https://leetcode.com/problems/coin-change-2/

Dynamic Programming
"""


class Solution:
    def change(self, amount: int, coins: "list[int]") -> int:
        n, m = len(coins), amount+1
        if amount == 0:
            return 1
        if n == 0:
            return 0
        coins.sort()
        arr = [[0 for i in range(m)] for j in range(n)]

        for j in range(m):
            arr[0][j] = int(j % coins[0] == 0)

        for i in range(1, n):
            arr[i][0] = 1
            for j in range(m):
                if coins[i] > j:
                    arr[i][j] = arr[i-1][j]
                else:
                    arr[i][j] = arr[i-1][j]+arr[i][j-coins[i]]

        print(arr)
        return arr[-1][-1]


if __name__ == "__main__":
    coins = [2, 3, 5, 10]
    w = 15
    s = Solution().change(w, coins)
    print(s)
