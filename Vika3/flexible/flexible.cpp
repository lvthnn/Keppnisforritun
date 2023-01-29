#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int w, p;
  cin >> w >> p;

  vector<int> v(p);
  for (auto& i : v)
    cin >> i;

  v.push_back(w);
  v.insert(v.begin(), 0);

  set<int> configs;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      if (i == j) continue;
      configs.insert(abs(v[i] - v[j]));
    }
  }

  for (auto& i : configs)
    cout << i << " ";

  return 0;
}
