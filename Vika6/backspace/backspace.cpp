#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  
  string input;
  cin >> input;

  stack<char> Q;
  for (int i = 0; i < input.size(); i++) {
    char curr = input[i];
    if (curr == '<') Q.pop();
    else Q.push(curr);
  }

  string res;
  while (!Q.empty()) {
    res += Q.top();
    Q.pop();
  }

  reverse(res.begin(), res.end());
  cout << res;

  return 0;
}
