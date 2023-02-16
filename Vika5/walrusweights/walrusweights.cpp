#include <iostream>
#include <vector>

using namespace std;

int walrus(vector<int> a) {

}

int main() {
  int n;
  cin >> n;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    
    v.push_back(t);
  }

  cout << walrus(v, v.size() - 1, 1000) << endl;

}
