"""
Shell sort algorithm in python.
Extended version of Insertion sort.
"""


def shell_sort(arr: list):
    """shell sort to sort the elements in place

    Args:
        arr (list): list of elements
    """
    size = len(arr)
    gap = size // 2

    while gap > 0:
        for i in range(gap, size):
            anchor = arr[i]
            j = i
            while j >= gap and arr[j - gap] > anchor:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = anchor
        gap //= 2


if __name__ == "__main__":
    tests = [
        [89, 78, 61, 53, 23, 21, 17, 12, 9, 7, 6, 2, 1],
        [],
        [1, 5, 8, 9],
        [243, 3, 1, 56, 34, 12, 1300],
        [5],
    ]
    # arr = [21, 38, 29, 17, 4, 25, 11, 32, 9]
    for test in tests:
        shell_sort(test)
        print(test)
