"""
Author      :       Kumar Shanu
Problem     :       Fractional Knapsack problem using Greedy method
"""


def find_maxProfit(weights: "list[int]", profits: "list[int]", capacity: "int", greedy_method: "str" = "max") -> float:
    """Fractional Knapsack Problem

    Find maximum profit using greedy method
    Args:

        weights (List[int]): list/array of weights
        profits (List[int]): list/array of profits
        capacity (int): total capacity of knapsack
        greedy_method (str):
            "min " - find maximum profit by considering minimum values first
            "max" - find maximum profit by considering maximum values first
            "optimal" - find maximum profit by considering profit/weight
    Returns:

        float: Maximum profit
    """
    if len(weights) != len(profits):
        print("Please provide correct values for profits and weights")
        return -1

    # make items/objects
    items = [{"weight": w, "profit": p} for w, p in zip(weights, profits)]

    # sort the items
    if greedy_method == "min":
        items = sorted(items, key=lambda x: x['weight'], )
    elif greedy_method == "max":
        items = sorted(items, key=lambda x: x['weight'], reverse=True)
    elif greedy_method == "optimal":
        items = sorted(
            items, key=lambda x: x['profit'] / x['weight'], reverse=True)
    else:
        raise Exception("please provide correct value for 'greedy_method' ")

    cur_weight, total_profit = 0, 0
    for i in range(len(weights)):
        if (cur_weight + items[i]['weight']) <= capacity:
            cur_weight += items[i]['weight']
            total_profit += items[i]['profit']
        else:
            remains = capacity - cur_weight
            total_profit += items[i]['profit'] * (remains / items[i]['weight'])
            break

    return total_profit


if __name__ == "__main__":
    weights = [3, 4, 6, 5]
    profits = [2, 3, 1, 4]
    w = 8
    print("Maximum profit in min case is: ", find_maxProfit(
        weights, profits, w, greedy_method="min"))
    print("Maximum profit in max case is: ", find_maxProfit(
        weights, profits, w, greedy_method="max"))
    print("Maximum profit in optimal case is: ", find_maxProfit(
        weights, profits, w, greedy_method="optimal"))
