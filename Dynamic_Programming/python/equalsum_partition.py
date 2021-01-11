

from Dynamic_Programming.python.subset_sum import isSubset_rec, isSubset_sum


def isEqual_sum_rec(arr: "list[int]", n: "int") -> bool:
    """Equal sum partition problem.
    Find out there exists partition in the array with equal sum.

    Solution using recursive subset_sum solution.

    Args:
    ---
        arr (list[int]): array of elements
        n (int): lenght of the array

    Returns:
    ---
        bool: True or False
    """
    # find sum of all elements
    s = 0
    for el in arr:
        s += el
    if(s % 2 == 1):
        return False
    else:
        return isSubset_rec(arr, n, s//2)


def isEqual_sum(arr: "list[int]", n: "int") -> bool:
    """Equal sum partition problem.
    Find out there exists partition in the array with equal sum.

    Solution using DP subset_sum solution.

    Args:

        arr (list[int]): array of elements
        n (int): lenght of the array

    Returns:

        bool: True or False
    """
    # find sum of all elements
    s = 0
    for el in arr:
        s += el
    if(s % 2 == 1):
        return False
    else:
        return isSubset_sum(arr, s//2)


if __name__ == "__main__":
    arr = [2, 3, 5, 7, 10]
    print("Subset exists with the given sum? ", isEqual_sum(arr, len(arr)))
