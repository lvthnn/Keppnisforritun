#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, i = 0;
	bool valid = true;
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		string curr;
		cin >> curr;
		
		if (curr != "mumble" && curr != to_string(i + 1)) {
			valid = false;
			break;
		}
	}

	if (valid) cout << "makes sense";
	else cout << "something is fishy";

    return 0;
}
