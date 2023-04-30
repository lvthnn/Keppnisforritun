#include <iostream>

using namespace std;

/**
 * Returns the differential sequence given an
 * integer array.
 *
 * @param a the integer array
 */
void seq_diff(int *a, int *diffa, int n) {
  int t = a[0];

  for (int i = 0; i < n; i++) {
    diffa[i] = a[i + 1] - t;
    t = a[i + 1];
  }
} 

/**
 * Prefix function for the Knuth-Morris-Pratt
 * substring search algorithm.
 *
 * @param a the target string
 * @param b the substring
 * @param m length of substring
 */
void prefix_function(int *a, int *b, int m)
{
    int i, j;
    for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
        while (j >= 0 && a[i] != a[j]) j = b[j];
}

/**
 * Knuth-Morris-Pratt algorithm for substring
 * searching in O(N) time
 *
 * @param s the target string
 * @param p the substring
 * @param r 
 *
 */
void kmp(int *s, int *p, int *r, int n, int m)
{
    int i, j, b[n + m + 2];
    int a[n + m + 1];
    for (i = 0; i < m; i++) a[i] = p[i];
    for (a[i++] = (1 << 30); i < n + m + 1; i++) a[i] = s[i - m - 1];
    prefix_function(a, b, n + m + 1);
    for (i = 0; i < n; i++) r[i] = i < n - m + 1 && b[i + 2*m + 1] >= m;
}

void print_array(int *a, int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{
  // Read in n and m
  int m, n;
  cin >> m >> n;

  // Pattern, mountain range, auxiliary
  int a[m], b[n], r[n - 1], diffa[m - 1], diffb[n - 1];

  // Cheeky reading of arrays
  for (int i = 0; i < n + m; i++) { 
    int t;
    cin >> t;

    if (i < m) a[i] = t;
    else b[i - m] = t;
  }

  seq_diff(a, diffa, m);
  seq_diff(b, diffb, n - 1);
  kmp(diffb, diffa, r, n - 1, m - 1);

  bool tyndur = 1;
  for (int i = 0; i < n - 1; i++) {
    if (r[i] == 1) {
      cout << i << " ";
      tyndur = 0;
    }
  }
  if (tyndur) cout << "tyndur";

  return 0;

}
