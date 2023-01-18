#include <iostream>

int main() {
  int x, y, quad;
  std::cin >> x >> y;

  if (x < 0 && y < 0)
    quad = 3;
  else if (x < 0 && y > 0)
    quad = 2;
  else if (x > 0 && y > 0)
    quad = 1;
  else
    quad = 4;
  std::cout << quad;

  return 0;
}
