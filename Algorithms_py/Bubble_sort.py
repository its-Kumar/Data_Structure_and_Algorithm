def bubble_sort(elements: list):
    """Sort the list inplace using bubble sort.

    Args:
    --
        elements (list): list of elements
    """
    size = len(elements)

    for i in range(size - 1):
        # if list is already sorted track it using swapped variable
        swapped = False

        for j in range(size - 1 - i):
            if elements[j] > elements[j + 1]:
                # swapping
                tmp = elements[j]
                elements[j] = elements[j + 1]
                elements[j + 1] = tmp
                swapped = True

        if not swapped:
            break


if __name__ == "__main__":
    elements = [5, 9, 2, 1, 67, 34, 88, 34]
    print(f"Before Sorting: {elements}")
    bubble_sort(elements)
    print(f"After sorting:  {elements} ")
