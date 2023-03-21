#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, m;
    cin >> n >> m;
    int N = n * m;
   
    // Lesa inn matrixuna
    int a[n][m];

    for (int i = 0; i < n; i++) {
        int line;
        cin >> line;
        
        int j = 0;
        while (line > 0) {
            a[i][j % m] = line % 10; 
            line /= 10; j++;
        }
        reverse(begin(a[i]), end(a[i]));
    }
   

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << a[i][j] << " ";
      cout << endl;
    }
}
