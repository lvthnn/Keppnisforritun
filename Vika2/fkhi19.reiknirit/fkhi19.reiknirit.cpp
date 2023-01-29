#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

bool cmp(ll i, ll j) { return i < j; }

bool cmp_ii(ii a, ii b) { 
  if (a.second == b.second) return a.first > b.first;
  return a.second > b.second; 
}

int main() {
  ll n;
  cin >> n;
  
  vector<ll> seq; // integer sequence
  for (ll k = 0; k < n; k++) {
    ll t;
    cin >> t;
    seq.push_back(t);
  }

  sort(seq.begin(), seq.end(), cmp);
  vector<ii> nums;

  for (ll i = 0, j = 0; j <= seq.size(); j++) {
    if (seq[i] != seq[j]) {
      nums.push_back(make_pair(seq[i], j - i));
      i = j;
    }
  }

  ll num_elements = n;
  // Í raun óþarfi að raða þessum lista
  // getum reiknað lokað snið með
  //
  // ∑_{i = 1}^k (i * h_i)
  //
  // sjá útskýringu á glærum.
  // Ef fallið er h_1 = h_2 = ... = h_k svo k = n
  /// þá er svarið ∑_{i = 1}^k i * h_i = ∑_{i = 1}^n i = n(n + 1)/2
  sort(nums.begin(), nums.end(), cmp_ii);
  for (ll i = 0; i < nums.size(); i++) {
    n -= nums[i].second;
    num_elements += n;
  }
    
  cout << num_elements << endl;

  return 0;
}
