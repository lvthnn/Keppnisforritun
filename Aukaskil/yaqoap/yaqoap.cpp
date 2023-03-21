#include <iostream>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

#define MAXN 1000000

ll sz[MAXN];

ll find(ll x) {
  return (sz[x] < 0) ? x : sz[x] = find(sz[x]);
}

void join(ll x, ll y) {
  ll r_x = find(x), r_y = find(y);

  if (r_x == r_y) return;
  if (sz[r_x] > sz[r_y]) sz[r_y] += sz[r_x], sz[r_x] = r_y;
  else sz[r_x] += sz[r_y], sz[r_y] = r_x;
}

ll size(ll x) {
  return -sz[find(x)];
}

int main() {
  ll n, q;
  cin >> n;

  for (ll i = 0; i < 200000; i++) sz[i] = 0;

  map<ll, bool> contains; // does the UF structure already contain this value?
  map<ll, ll>   dict;     // dictionary mapping values to their indices in a[]

  ll a[n];

  for (ll i = 0; i < n; i++) {
    ll curr; 
    cin >> curr;

    if (contains[curr]) {
      ll tmp = dict[curr];  
      sz[i]--;

      join(i, tmp);
      a[i] = curr;
    }
    else {
      a[i] = curr;
      contains[curr] = true;
      dict[curr] = i;
      sz[i]--;
    }

  }

  cin >> q;
  ll i, j;

  for (ll k = 0; k < q; k++) {
    cin >> i >> j;
    cout << size(i - 1) << " ";
    join(i - 1, j - 1);
    cout << size(j - 1) << endl;
  }

  return 0;
}
