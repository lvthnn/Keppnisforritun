#include <iostream>
#include <vector>
#define MAXN 1000000

using namespace std;

int main() {
  int n;
  cin >> n;

  int nums[n];
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;

    nums[i] = t;
  }

  bool w[MAXN] = {0};

  for (int i = 0; i < n; i++) {
    int wcurr = nums[i];
    for (int j = sizeof(w) - 1; j >= 0; j--)
      if (w[j] == true && j+wcurr < sizeof(w))
        w[j + wcurr] = true;

    w[wcurr] = true;
  }

  for (int i = 0; i < sizeof(w); i++)
    if (w[i] == true) cout << i << endl;

}
