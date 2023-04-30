#include <stdio.h>
void prefix_function(int *a, int *b, int m)
{
    int i, j;
    for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
        while (j >= 0 && a[i] != a[j]) j = b[j];
}

void kmp(int *s, int *p, int *r, int n, int m)
{
    int i, j, b[n + m + 2];
    int a[n + m + 1];
    for (i = 0; i < m; i++) a[i] = p[i];
    for (a[i++] = (1 << 30); i < n + m + 1; i++) a[i] = s[i - m - 1];
    prefix_function(a, b, n + m + 1);
    for (i = 0; i < n; i++) r[i] = i < n - m + 1 && b[i + 2*m + 1] >= m;
}

int main()
{
    int i, n, m;
    scanf("%d%d", &m, &n);
    int P[m], M[n];
    for (i = 0; i < m; i++) scanf("%d", a + i);
    for (i = 0; i < n; i++) scanf("%d", b + i);
    ...
    return 0;
}
