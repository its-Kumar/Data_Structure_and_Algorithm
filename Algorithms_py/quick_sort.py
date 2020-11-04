def swap(a: int, b: int, arr: list):
    """swap elements of array

    Args:
        a (int): index 1
        b (int): index 2
        arr (list): list of elements
    """
    if a != b:
        temp = arr[a]
        arr[a] = arr[b]
        arr[b] = temp


def partition(elements: list, start: int, end: int) -> int:
    pivot_index = start
    pivot = elements[pivot_index]

    while start < end:
        while start < len(elements) and elements[start] <= pivot:
            start += 1

        while elements[end] > pivot:
            end -= 1

        if start < end:
            swap(start, end, elements)
    swap(pivot_index, end, elements)
    return end


def quick_sort(elements: list, start: int, end: int):
    """Quick sort implementation. Sort a list using quick sort between
    boundries 'start' and 'end'.
        Time Complexity:
        Average case: O(nlogn)
        Worst case: O(n^2)

    Args:
        elements (list): list of elements
        start (int): starting index
        end (int): ending index
    """
    if start < end:
        pi = partition(elements, start, end)
        # left partition
        quick_sort(elements, start, pi - 1)
        # right partition
        quick_sort(elements, pi + 1, end)


if __name__ == "__main__":
    arr = [7, 9, 0, 29, 2, 11, 15, 28]
    print("Array is : ", arr)
    quick_sort(arr, 0, len(arr) - 1)
    print("Array is : ", arr)
