def linear_search(lst: list, n: int) -> int:
    """Find a element in the list and return index if found otherwise return -1

    Args:
        lst (list): List of elements
        n (int or Any): number to find

    Returns:
        int: index of the element
    """
    for index, element in enumerate(lst):
        if element == n:
            return index
    return -1


def binary_search(lst: list, n: int) -> int:
    """Search any element in a list using binary search and return its index
        or -1

    Args:
        lst (list): List of elements
        n (int or any): element to find

    Returns:
        int: index of the element
    """
    left_index = 0
    right_index = len(lst) - 1
    mid_index = 0

    while left_index <= right_index:
        mid_index = (left_index + right_index) // 2
        if lst[mid_index] == n:
            return mid_index
        if lst[mid_index] < n:
            left_index = mid_index + 1
        else:
            right_index = mid_index - 1
    return -1


def binary_search_recursive(
    lst: list, n: int, left_index: int, right_index: int
) -> int:
    """Search any element in a list using recursive binary search and return
        index of element.

    Args:
        lst (list[int]): List of elements
        n (int): element to find
        left_index (int): starting index
        right_index (int): ending index

    Returns:
        int: index of element
    """
    if right_index < left_index:
        return -1

    mid_index = (left_index + right_index) // 2
    if lst[mid_index] == n:
        return mid_index

    if lst[mid_index] < n:
        left_index = mid_index + 1
    else:
        right_index = mid_index - 1
    return binary_search_recursive(lst, n, left_index, right_index)


if __name__ == "__main__":
    numbers_list = [12, 15, 17, 19, 21, 24, 45, 57]
    number_to_find = 17
    index = linear_search(numbers_list, number_to_find)
    print(f"Number found at index {index} using linear search.")
    index = binary_search(numbers_list, number_to_find)
    print(f"Number found at index {index} using binary search.")
    index = binary_search_recursive(
        numbers_list, number_to_find, 0, len(numbers_list) - 1
    )
    print(f"Number found at index {index} using recursive binary search.")
