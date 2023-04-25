#include <iostream>
#include <vector>
#include <math.h>
#define MAXN 1000000

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    cout << 1 << endl;
    for(ll i = 2;  i <= sqrt(n); i++) {
      if (n % i == 0) {
        if (n/i != i)
            cout << i << endl << n/i<< endl;
        else
            cout << i << endl;
      }
    }
    if (n > 1) cout << n << endl;

    return 0;
}
