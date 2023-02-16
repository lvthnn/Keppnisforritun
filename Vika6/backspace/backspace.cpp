#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string a;
  cin >> a;

  for (int i = a.size()-1; i > 0; i--)
    if (a[i] != '<') cout << a[i-1];

}
