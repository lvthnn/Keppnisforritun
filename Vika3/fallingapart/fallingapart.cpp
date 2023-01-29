#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ints(n);

  for (auto& i : ints)
    cin >> i;

  sort(ints.rbegin(), ints.rend());

  int alice = 0, bob = 0;
  for (int i = 0; i < ints.size(); i++) {
    if (i % 2 == 0) alice += ints[i];
    else bob += ints[i];
  }

  cout << alice << " " << bob << endl;
}
