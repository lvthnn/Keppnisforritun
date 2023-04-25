#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

int main() {

  double V;
  cin >> V;

  double r = pow(3.0 / (4.0 * M_PI) * V, 1.0 / 3.0);
  cout << 4 * M_PI * pow(r, 2.0) << endl;

}
