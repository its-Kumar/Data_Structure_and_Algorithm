def search(lst: list, target: int):
    """search the element in list and return index of all the occurances

    Args:
        lst (list): List of elements
        target (int): Element to find

    Returns:
        list: list of index.
    """
    left = 0
    right = len(lst) - 1
    mid = 0
    index = []
    while left <= right:
        mid = (left + right) // 2
        if lst[mid] == target:
            index.append(mid)
        if lst[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    # search in left side
    i = index[0] - 1
    while i >= 0:
        if lst[i] == target:
            index.append(i)
        i -= 1
    # search in right side
    i = index[0] + 1
    while i < len(lst):
        if lst[i] == target:
            index.append(i)
        i += 1
    return sorted(index)


if __name__ == "__main__":
    numbers = [1, 4, 6, 9, 11, 11, 13, 15, 15, 15, 17, 21, 34, 53]
    number_to_find = 15
    index = search(numbers, number_to_find)
    print(f"Number {number_to_find} found at {index} index.")
