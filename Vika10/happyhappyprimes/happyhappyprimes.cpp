#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 10000

// perfect digital invariant
int pdi(int num, int base) {
  int total = 0;
  while (num > 0) {
    total += (num % base) * (num % base);
    num = num / base;
  }
  return total;
}

bool is_prime(int num) {
  for (int i = 2; i <= sqrt(num); i++)
    if (num % i == 0) return false;
  return true;
}

bool is_happy(int i) {
  if (i == 1) return false;
  int marked[MAXN] = {0};
  while(i > 1 && marked[i] == 0) {
    marked[i] = 1;
    i = pdi(i, 10);
  }
  return i == 1;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int index, num;
    cin >> index >> num;

    bool res = is_happy(num) && is_prime(num);
    cout << index << " " << num << " " << (res ? "YES" : "NO") << endl;
  }

  return 0;
}
