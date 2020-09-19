#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Recursive solution (time complexity = O(2^n)

int lcs(char *s1, char *s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (s1[m - 1] == s2[n - 1])
        return 1 + lcs(s1, s2, m - 1, n - 1);
    else
        return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
}

// Solution with Memorization (time complexity = O(m X n)
int lcs(char *s1, char *s2, int m, int n)
{
    int lst[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lst[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                lst[i][j] = lst[i - 1][j - 1] + 1;
            else
                lst[i][j] = max(lst[i - 1][j], lst[i][j - 1]);
        }
    return lst[m][n];
}

// Recursive solution with Memorization
int lcs(char *s1, char *s2, int m, int n, int lst[][10])
{
    if (m == 0 || n == 0)
        return 0;
    // if already stored in table
    if (lst[m - 1][n - 1] != -1)
        return lst[m - 1][n - 1];

    if (s1[m - 1] == s2[n - 1])
    {
        // Store in table to avoid repeatation
        lst[m - 1][n - 1] = 1 + lcs(s1, s2, m - 1, n - 1, lst);
        return lst[m - 1][n - 1];
    }
    else
    {
        lst[m - 1][n - 1] = max(lcs(s1, s2, m, n - 1, lst), lcs(s1, s2, m - 1, n, lst));
        return lst[m - 1][n - 1];
    }
}

int main()
{
    char *s1 = "ABCDGH";
    char *s2 = "AEDFHR";
    int m = strlen(s1);
    int n = strlen(s2);
    int lst[m + 1][10];
    memset(lst, -1, sizeof(lst));

    printf("Longest common subsequence lenght is : %d", lcs(s1, s2, m, n, lst));
    //printf("Longest common subsequence lenght is : %d",lcs(s1,s2,m,n));

    return 0;
}
