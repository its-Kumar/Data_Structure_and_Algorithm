"""
Problem description:  Given that we can climb either one or two steps at a time, determine the no of ways to climb the nth step
Problem category:  Dynamic Programming
"""

def find_ways_brute_force(n):
    """
    :param n: stair n
    :return: no of ways to reach n
    """

    """
    when we are at ith stair no of ways to reach it is simply the sum of no of ways to reach (i-1)stair and (i-2)stair 
    """

    # Base cases
    if n == 1:
        return 1
    if n == 2:
        return 2

    return find_ways_brute_force(n-1) + find_ways_brute_force(n-2)

    # Time Complexity :- O(2^n)
    # Space complexity :- O(1)



def find_ways_dp(n):
    """
    :param n: stair n
    :return: no of ways to reach n
    """
    if n == 1: # base case
        return 1

    if n == 2: # we can reach from step 1 or directly jump to step 2
        return 2
    """
    when we are at ith stair no of ways to reach it is simply the sum of no of ways to reach (i-1)stair and (i-2)stair 
    """


    no_of_ways_prev_prev = 1
    no_of_ways_prev = 2

    for i in range(3,n+1):
        no_of_ways_curr =  no_of_ways_prev + no_of_ways_prev_prev
        no_of_ways_prev_prev = no_of_ways_prev
        no_of_ways_prev = no_of_ways_curr

    return no_of_ways_curr

    # Time Complexity :- O(n)
    # Space complexity :- O(1)


# main function
if __name__ == "__main__":
    n = 10
    print("The number of ways we can reach the nth step is : " + str(find_ways_dp(n)))

