#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int no; // phone no
    cin >> no;

    int cnt = 0;
    for (int j = 1; j <= sqrt(no); j++) if (no % j == 0) 
      cnt++;

    if (cnt == 6) printf("%018d", no);

  }
  
}
