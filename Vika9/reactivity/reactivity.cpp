#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, k;
    cin >> n >> k;
    
    vvi g(n);
    vi indegree(n, 0);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        g[b].push_back(a);
        indegree[a]++;
    }

    vi res;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        if (q.size() > 1) {
            cout << "back to the lab" << endl;
            break;
        }

        int current = q.front();
        q.pop();
        res.push_back(current);

        for (int neighbor : g[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (q.empty()) {
        if (res.size() != n) {
            cout << "back to the lab" << endl;
        } else {
            for (int i = res.size() - 1; i >= 0; i--) {
                cout << res[i] << (i > 0 ? " " : "\n");
            }
        }
    }

    return 0;
}
