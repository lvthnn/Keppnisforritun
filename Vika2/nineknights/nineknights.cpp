#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

/**
 * Check whether two knights are in
 * positions to attack each other.
 *
 * @param a first knight
 * @param b second knight
 * @return can they attack each other
 */
bool check_pair(ii a, ii b) {
  return (abs(a.first - b.first) == 2 && abs(a.second - b.second) == 1 ||
          abs(a.first - b.first) == 1 && abs(a.second - b.second) == 2);
}

int main() {
  vector<ii> knights; // vector of knights 
  bool valid = true;  // result

  // record knight positions 
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      char curr;
      cin >> curr;

      if (curr == 'k') knights.push_back(make_pair(i, j));
    }
  }

  // check knights pairwise
  if (knights.size() != 9) valid = false;
  else {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (i == j) continue;
        else if (check_pair(knights[i], knights[j])) valid = false;
      }
    }
  }

  cout << (valid ? "valid" : "invalid") << endl;

  return 0;
}
