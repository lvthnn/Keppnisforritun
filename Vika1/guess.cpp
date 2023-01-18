#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int lo = 1;
	int hi = 1000;
	
	for (int i = 0; i < 10; i++) {
		int mid = (lo + hi) / 2;
		cout << mid << endl;

		string answer;
		cin >> answer;

		if (answer == "lower") hi = mid - 1;
		else if (answer == "higher") lo = mid + 1;
		else break;
	}	
	
	return 0;
}
