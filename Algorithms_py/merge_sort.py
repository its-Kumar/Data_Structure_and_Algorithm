"""Merge sort Algorithm in python"""


def merge(a: list, b: list, arr: list):
    """merge two sorted lists in place

    Args:

        a (list): first sorted list
        b (list): second sorted list
        arr (list): orignal list to store sorted elements
    """
    len_a = len(a)
    len_b = len(b)
    i = j = k = 0

    while i < len_a and j < len_b:
        if a[i] <= b[j]:
            arr[k] = a[i]
            i += 1
        else:
            arr[k] = b[j]
            j += 1
        k += 1

    while i < len_a:
        arr[k] = a[i]
        k += 1
        i += 1

    while j < len_b:
        arr[k] = b[j]
        k += 1
        j += 1


def merge_sort(arr: list):
    """
    Merge Sort: Sort the list in place using merge sort algorithm

    Args:

        arr (list): list of elements
    """
    if len(arr) <= 1:
        return

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    merge_sort(left)
    merge_sort(right)
    merge(left, right, arr)


if __name__ == "__main__":
    arr = [10, 3, 15, 7, 8, 23, 98, 29]
    merge_sort(arr)
    print(arr)
