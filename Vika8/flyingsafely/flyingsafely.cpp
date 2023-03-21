#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
void dfs(vvi& g, int x) {
  v[x] = 1;

  for (int i = 0; i < g[x].size(); i++)
    if (v[g[x][i]] == 0) dfs(g, g[x][i]);
}

void print(vvi& g, int n) {
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ": ";
    for (int j = 0; j < g[i].size(); j++) cout << g[i][j] + 1 << " ";
    cout << endl;
  }
}

int main () {
  int tf, n, m, x, y;

  cin >> tf;
  for (int t = 0; t < tf; t++) {
    cin >> n >> m;

    vvi g(n);
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      x--; y--;

      g[x].push_back(y);
      g[y].push_back(x);
    }

    v.assign(n, 0);
    dfs(g, 0);

    int sus = 0;
    for (int i = 0; i < v.size(); i++)
      sus += v[i];
    
    cout << sus - 1 << endl;

  }

  return 0;

}
