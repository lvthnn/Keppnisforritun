#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

// scores an arrangement
ll score(vector<ll> arr) {
  ll score = 0;
  for (ll i = 0; i < arr.size() - 1; i++)
    score += pow((arr[i] - arr[i + 1]), 2);
  return score;
}

int main() {
  ll n;
  cin >> n;

  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    ll curr;
    cin >> curr;
    v.push_back(curr);
  }


  sort(v.rbegin(), v.rend());
  cout << score(v) << endl;

  return 0;
}
