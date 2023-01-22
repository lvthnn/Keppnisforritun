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
  
  if (n == 0) cout << 0 << endl;
 
  else {
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
    sort(nums.begin(), nums.end(), cmp_ii);
    for (ll i = 0; i < nums.size(); i++) {
      n -= nums[i].second;
      num_elements += n;
    }
      
    cout << num_elements << endl;
  }

  return 0;
}
