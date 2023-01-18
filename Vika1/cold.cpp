#include <iostream>

int main() {
    int n, temp, count;
    std::cin >> n;
    count = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        if (temp < 0) count++;
    }
    std::cout << count << std::endl;
    return 0;
}