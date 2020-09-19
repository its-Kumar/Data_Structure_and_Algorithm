
#include <stdio.h>

void sort(int p[], int w[], float p_w[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p_w[j] < p_w[j + 1])
            {
                tmp = p_w[j];
                p_w[j] = p_w[j + 1];
                p_w[j + 1] = tmp;
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
                tmp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tmp;
            }
        }
    }
}

float Greedy_knapsack(int p[], int w[], int n, int m)
{
    int i;
    float profit = 0, p_w[n];
    for (i = 0; i < n; i++)
        p_w[i] = (float)p[i] / (float)w[i];

    printf("\nProfit/Weight matrix is :\n");
    for (int i = 0; i < n; i++)
        printf("%5.2f", p_w[i]);
    sort(p, w, p_w, n);
    for (i = 0; i < n; i++)
    {
        if (m > 0 && w[i] <= m)
        {
            m -= w[i];
            profit += p[i];
        }
        else
            break;
    }
    if (m > 0)
        profit += p[i] * ((float)m / (float)w[i]);
    return profit;
}

int main()
{
    int m, n, w[20], p[20];
    printf("Enter the capacity of knapsack : ");
    scanf("%d", &m);
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

    printf("\nMaximum profit is : %.3f", Greedy_knapsack(p, w, n, m));

    return 0;
}
