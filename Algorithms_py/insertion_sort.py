def insertion_sort(elements: list) -> None:
    """Sort the list using insertion sort algorithm.

    Args:
        elements (list): list of elements
    """
    for i in range(1, len(elements)):
        anchor = elements[i]
        j = i - 1
        while j >= 0 and anchor < elements[j]:
            elements[j + 1] = elements[j]
            j -= 1
        elements[j + 1] = anchor


if __name__ == "__main__":
    arr = [eval(x) for x in input("Enter the array: ").split()]
    print("Array is: ", arr)
    insertion_sort(arr)
    print("Array is: ", arr)
