#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char *s1, char *s2, int m, int n)
{
    int lst[m + 1][n + 1];
    int i, j, index;

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
    index = lst[m][n];
    char str[index + 1];
    str[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            str[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (lst[i][j - 1] > lst[i - 1][j])
            j--;
        else
            i--;
    }
    printf("\nThe LCS is =");
    puts(str);
    return lst[m][n];
}
int main(void)
{
    char *s1 = "ABCDGH";
    char *s2 = "AEDFHR";
    int m = strlen(s1);
    int n = strlen(s2);

    printf("\nLongest common subsequence lenght is : %d", lcs(s1, s2, m, n));
    return 0;
}
