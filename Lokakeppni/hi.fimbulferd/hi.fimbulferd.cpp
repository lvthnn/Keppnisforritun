#include <iostream>
#include <vector>
#define INF (1 << 30)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;

vi bellman_ford(vvii& g, ll s)
{
    ll i, j, k, n = g.size(), x, w, q[n];
    vi d(n);

    for (i = 0; i < n; i++) d[i] = (i == s) ? 0 : INF, 
                            q[i] = (i == s) ? 0 : -1;

    for (i = 0; i < n - 1; i++) for (j = 0; j < n; j++) if (q[j] == i)
        for (k = 0; k < g[j].size(); k++) {
            x = g[j][k].first, w = g[j][k].second;
            if (d[j] + w < d[x]) d[x] = d[j] + w, 
                                 q[x] = i + 1;
        }
    
    for (i = 0; i < n - 1; i++) for (j = 0; j < n; j++) if (q[j] == n + i - 1)
        for (k = 0; k < g[j].size(); k++) {
            x = g[j][k].first, w = g[j][k].second;
            if (d[x] != -INF && d[j] + w < d[x]) d[x] = -INF, 
                                                 q[x] = n + i;
        }

    return d;
}

int main()
{
    ll V, E, Q, a, b, w;
    cin >> V >> E >> Q;
    vvii g(V);

    // read in edges
    for (ll i = 0; i < E; i++)
    {
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back(ii(b, w));
    }
    
    // process queries
    for (ll i = 0; i < Q; i++) {
      ll src, sink;
      cin >> src >> sink;
      src--; sink--;

      vi d = bellman_ford(g, src);

      if (d[sink] == INF) printf("engin leid\n");
      else if (d[sink] == -INF) printf("nogu hlytt\n");
      else printf("%lld\n", d[sink]);
    }

    return 0;
}
