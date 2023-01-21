#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

bool strcomp(string a, string b) { return a < b; } 

int main() {
  int t; // number of cases
  cin >> t;

  regex r("\\s+"); // for deleting whitespace

  for (int i = 0; i < t; i++) {
    vector<string> matches; // songs matching criterion

    int n; // number of songs
    cin >> n;

    cin.ignore(256, '\n');

    string bandname;
    getline(cin, bandname);
    cout << bandname << ": " << endl;
    int band_len = regex_replace(bandname, r, "").length();

    for (int j = 0; j < n; j++) {
      string songname;
      getline(cin, songname);
      int song_len = regex_replace(songname, r, "").length();

      if (song_len == band_len) matches.push_back(songname);
    }

    sort(matches.begin(), matches.end(), strcomp);
    for (int j = 0; j < matches.size(); j++)
      cout << matches[j] << endl;

  }
  
  return 0;
}
