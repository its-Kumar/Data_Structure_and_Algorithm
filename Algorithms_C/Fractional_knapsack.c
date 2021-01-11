/************************************************
 *  Author  -   Kumar Shanu                                           *
 *  Problem -   Greedy Fractional  Knapsack problem     *
 *  Find out the maximum profit                                    *
 * ***********************************************
*/

#include <stdio.h>

// booleans
enum
{
    false,
    true
};

// knapsack items with thier weights and profit
struct Item
{
    // weight of item
    int weight;
    // profit we get if we include item
    int profit;
};

/**
    Sort The items according to the value of the key

        @param items array of items
        @param n length of the items array
        @param key  value of key
            "weight" - sort by weight
            "profit" - sort by profit
            "profit/weight", "p/w" - sort by profit/ weight value
        @return sorted array of items
    */
void sort(struct Item items[], int n, char key[], int reverse)
{
    struct Item tmp;
    float obj1, obj2;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (key == "weight")
            {
                obj1 = items[j].weight;
                obj2 = items[j + 1].weight;
            }
            else if (key == "profit")
            {
                obj1 = items[j].profit;
                obj2 = items[j + 1].profit;
            }
            else if (key == "profit/weight" || key == "p/w")
            {
                obj1 = (float)items[j].profit / (float)items[j].weight;
                obj2 = (float)items[j + 1].profit / (float)items[j + 1].weight;
            }
            else
            {
                printf("Invalid value for key");
                return;
            }
            if (reverse)
            {
                if (obj1 < obj2)
                {
                    tmp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = tmp;
                }
            }
            else
            {
                if (obj1 >= obj2)
                {
                    tmp = items[j];
                    items[j] = items[j + 1];
                    items[j + 1] = tmp;
                }
            }
        }
    }
}

/**
*   Greedy Knapsack problem
*   @param n(int) -    length of "profits" array
*   @param profits(int[]) -    array of profits
*   @param m(int) - length of "weights" array
*   @param weights(int[]) -  array of weights
*   @param capacity(int) -  total capacity of knapsack
*   @param greedy_method(char[]) -  greedy method to calculate max profit
*           "min" - consider minimum values first
*           "max" - consider maximum values first
*           "optimal" - consider maximum weight/profit values first
* @return  the maximum profit using greedy method.
*/
float Greedy_knapsack(int n, int profits[], int m, int weights[], int capacity, char greedy_method[])
{
    if (n != m)
    {
        printf("Please provide correct values for profits and weights");
        return -1;
    }
    // create items/objects
    struct Item items[n];
    for (int i = 0; i < n; i++)
    {
        struct Item itm;
        itm.weight = weights[i];
        itm.profit = profits[i];
        items[i] = itm;
    }
    float total_profit = 0;
    int cur_weight = 0;

    // sort the items
    if (greedy_method == "min")
        sort(items, n, "profit", false);
    else if (greedy_method == "max")
        sort(items, n, "profit", true);
    else if (greedy_method == "optimal")
        sort(items, n, "profit/weight", true);
    else
    {
        printf("please provide correct value for 'greedy_method' ");
        return -1;
    }

    // calculate the profit
    for (int i = 0; i < n; i++)
    {
        if (cur_weight + items[i].weight <= capacity)
        {
            cur_weight += items[i].weight;
            total_profit += items[i].profit;
        }
        else
        {
            int remains = capacity - cur_weight;
            total_profit += items[i].profit * ((float)remains / (float)items[i].weight);
            break;
        }
    }
    //return the total profit
    return total_profit;
}

int main()
{
    int capacity, n, w[20], p[20];
    printf("Enter the capacity of knapsack : ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight matrix : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profit matrix : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\nWeight matrix is :\n");
    for (int i = 0; i < n; i++)
        printf("%5d", w[i]);
    printf("\nProfit matrix is :\n");
    for (int i = 0; i < n; i++)
        printf("%5d", p[i]);

    printf("\nMaximum profit in min case is : %.3f", Greedy_knapsack(n, p, n, w, capacity, "min"));
    printf("\nMaximum profit in max case is : %.3f", Greedy_knapsack(n, p, n, w, capacity, "max"));
    printf("\nMaximum profit in optimal case is : %.3f", Greedy_knapsack(n, p, n, w, capacity, "optimal"));

    return 0;
}
