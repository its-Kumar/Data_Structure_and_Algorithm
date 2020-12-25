"""
Author : Kumar Shanu
Problem :  Longest Common Subsequence

Dynamic Programming
"""


def LCS(x: str, y: str) -> int:
    """find Longest common subsequence using dynamic programming

    Args:

        x (str): first string
        y (str): second string

    Returns:

        int: lenght of the longest common subsequence
    """
    m, n = len(x), len(y)
    if m == 0 or n == 0:
        return 0

    dp = [[0 for _ in range(n+1)] for _ in range(m+1)]

    for i in range(1, m+1):
        for j in range(1, n+1):
            if(x[i-1] == y[j-1]):
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[-1][-1]


memo = [[-1 for _ in range(50)] for _ in range(50)]


def LCS_memo(x: str, y: str, m: int, n: int) -> int:
    """find the lenght of longest common subsequence using recursion
    with memorization.

    Args:

        x (str): first string
        y (str): second string
        m (int): lenght of first string. Defaults to len(x).
        n (int): length of second string. Defaults to len(y).

    Returns:

        int: lenght of the lcs
    """
    if(m == 0 or n == 0):
        return 0

    # if already stored in table
    if(memo[m-1][n-1] != -1):
        return memo[m-1][n-1]

    if(x[m-1] == y[n-1]):

        # store into table to avoid repeatation
        memo[m-1][n-1] = 1 + LCS_memo(x, y, m-1, n-1)
    else:
        memo[m-1][n-1] = max(LCS_memo(x, y, m, n-1), LCS_memo(x, y, m-1, n))

    return memo[m-1][n-1]


if __name__ == "__main__":
    s1 = "abaaba"
    s2 = "babbab"
    # print("length of longest common subsequence is: ", LCS(s1, s2))
    print("length of longest common subsequence is: ",
          LCS_memo(s1, s2, len(s1), len(s2)))
