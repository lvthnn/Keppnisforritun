#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;


// gets test case
ii get_case() {
  int n, m;
  cin >> n >> m;

  return make_pair(n, m);
}

int main() {
 
  // initialize
  ii test_case = get_case();
  ii o = make_pair(0,0);

  // do until last case is encountered 
  while (test_case != o) {
    int n = test_case.first;
    int m = test_case.second;

    vector<int> h(n);
    for (auto& i : h)
      cin >> i;

    vector<int> k(m);
    for (auto& i : k)
      cin >> i;

    sort(h.begin(), h.end());
    sort(k.begin(), k.end());

    // i is index of dragon, j is index of knight
    int i = 0, j = 0, cost = 0;
    while (i < n && j < m) {
      if (h[i] <= k[j]) {
        cost += k[j];
        i++; 
      }
      j++;
    }
    if (i == n) cout << cost << endl;
    else cout << "Loowater is doomed!" << endl;


    // update test case and move on
    test_case = get_case();

  }

  return 0;
}
