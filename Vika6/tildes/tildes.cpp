#include <iostream>
#include <vector>

using namespace std;

// Weighted Union-Find
class UnionFind {
  public:
    vector<int> id;
    vector<int> sz;

    UnionFind(int n) {
      for (int i = 0; i < n; i++) {
        id.push_back(i);
        sz.push_back(1);
      }
    };

    int find(int p) {
      while (p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
      }

      return p;
    }

    void join(int p, int q) {
      int i = find(p);
      int j = find(q);
      if (i == j) return;

      if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
      else               { id[j] = i; sz[i] += sz[j]; }
    }
};

int main() {
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  for (int i = 0; i < q; i++) {
    char t;     // query type
    int p1, p2; // parameters
    
    cin >> t;
    if (t == 't') {
      cin >> p1 >> p2;
      p1 -= 1; p2 -= 1;
      uf.join(p1, p2);
    }

    else if (t == 's') {
      cin >> p1;
      cout << uf.sz[uf.find(p1-1)] << endl;
    }

  }

  return 0;
}
