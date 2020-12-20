"""
KUMAR SHANU
Program: find nth fibnacci number
"""

# recursive function for nth fibnacci number


def fib(n):
    return (1, 0)[n < 1] if n < 2 else fib(n-1) + fib(n-2)


# recursive function using memorization
memo = [-1]*100


def fib(n):
    if n <= 1:
        return n
    if memo[n-1] != -1:
        first = memo[n-1]
    else:
        first = fib(n-1)

    if memo[n-2] != -1:
        second = memo[n-2]
    else:
        second = fib(n-2)

    memo[n] = first + second
    return memo[n]


# iterative function using dynamic programming

def fib(n):
    dp = [-1]*(n+1)
    dp[0], dp[1] = 0, 1

    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]

    return dp[n]


if __name__ == "__main__":
    n = int(input("Enter n: "))
    print("nth fibnacci number is: ", fib(n))
