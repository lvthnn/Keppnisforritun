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
      while (p != id[p]) p = id[p];
      return p;
    }

    void union_of(int p, int q) {
      int i = find(p);
      int j = find(q);
      if (i == j) return;

      if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; cout << "Size of " << j << ": " << sz[j] << endl; }
      else               { id[j] = i; sz[i] += sz[j]; cout << "Size of " << i << ": " << sz[i] << endl; }
    }
};

void read_query(UnionFind uf) {
  char t;     // query type
  int p1, p2; // parameters
  
  cin >> t;
  if (t == 't') {
    cin >> p1 >> p2;
    p1 -= 1; p2 -= 1;
    uf.union_of(p1, p2);
  }

  else if (t == 's') {
    cin >> p1;
    cout << uf.sz[uf.find(p1)] << endl;
  }
}

int main() {
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  for (int i = 0; i < q; i++)
    read_query(uf);

  return 0;
}
