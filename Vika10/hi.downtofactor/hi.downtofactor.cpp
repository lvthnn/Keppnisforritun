#include <iostream>
#include <cstdio>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

ll bigprod(ll x, ll y, ll m)
{
    return ((lll)x*y)%m;
}

ll modpow(ll x, ll n, ll m)
{ 
    ll r = 1;
    while (n > 0) 
    { 
        if (n%2 == 1) r = bigprod(r, x, m);
        n = n/2;
        x = bigprod(x, x, m);
    } 
    return r; 
}

int miller_rabin(ll n)
{
    if (n%2 == 0) return n == 2;
    if (n <= 3)   return n == 3;

    ll i, k, s = 0, d = n - 1, 
       t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    while (d%2 == 0) d /= 2, s++;

    for (k = 0; k < 12; k++) if (t[k] <= n - 2)
    {
        ll a = t[k];
        ll x = modpow(a, d, n);

        if (x == 1 || x == n - 1) 
          continue;
        for (i = 0; i < s - 1; i++) if ((x = bigprod(x, x, n)) == n - 1) 
          break;
        if (i == s - 1) return 0;
    }
    return 1;
}

int main() 
{
  srand(time(NULL));

  ll k;
  cin >> k;

  for (ll i = 0; i < k; i++) 
  {
    ll no;
    cin >> no;

    ll rt = ceil(sqrt(no));
    if (rt * rt == no && miller_rabin(rt) == 1) printf("%018lld\n", no);
  }
}
