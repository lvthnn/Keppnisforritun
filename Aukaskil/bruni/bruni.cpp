#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

bool cmp_fi(const ii& lh, const ii& rh) { return lh.first < rh.first; }
bool cmp_ti(const ii& lh, const ii& rh) { return lh.second < rh.second; }

int find(int x, int y, vvi& F, vii& post) {

    if(y < 0) return -10000000;
	
    int a = F[x][y];
    if (a != -1) return a;
	
    else {
        ii p = post[x - 1];
        int tx = p.first, fx = p.second;
		
        if (x == 0) {
            F[x][y] = 0;
            return 0;
        }
        else if (tx > y){
            F[x][y] = find(x - 1, y, F, post);
            return F[x][y];
        }
        else {
            F[x][y] = max(find(x - 1, y, F, post), fx + find(x - 1, y + fx - tx, F, post));
            return F[x][y];
        }
    }
}

int main() {
	int n, t;
	cin >> n >> t;
	
	vii pre, post;
	
	for (int i = 0; i < n; i++) {
		int ti, fi;
		cin >> ti >> fi;
		
		if (ti <= fi) pre.push_back(make_pair(ti, fi));
		else post.push_back(make_pair(ti, fi));
	}
	
	sort(pre.begin(), pre.end(), cmp_fi);
	sort(post.begin(), post.end(), cmp_ti);
	
	int t_elapsed = 0, dur = 0;
	int t_left = t;

	for (int i = 0; i < pre.size(); i++) {
		ii p = pre[i];
		int ti = p.first, fi = p.second;
		
		if (ti <= t_left) {
			dur = fi - ti;
			t_left += dur;
			t_elapsed += ti;
		}
	}	

    n = post.size();
    vvi F = vvi(post.size() + 1, vector<int>(t_left + 1, -1));
    cout << t_left + find(n, t_left, F, post) + t_elapsed;
	
}
