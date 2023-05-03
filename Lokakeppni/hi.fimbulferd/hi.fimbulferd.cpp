#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define INF (1LL << 60)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vi dijkstra(vvii& g, ll s)
{
    ll i, x, w, n = g.size();
    vi d(n, INF);
    priority_queue<ii> q;
    q.push(ii(-0, s)), d[s] = 0;
    while (q.size() > 0)
    {
        w = -q.top().first, x = q.top().second, q.pop();
        if (w > d[x]) continue;
        for (i = 0; i < g[x].size(); i++)
        {
            if (d[g[x][i].first] <= w + g[x][i].second) continue;
            q.push(ii(-(w + g[x][i].second), g[x][i].first));
            d[g[x][i].first] = w + g[x][i].second;
        }
    }
    return d;
}

ll dfs(vvii& g, ll u, ll d, ll *s, ll *a, ll *l)
{
    l[u] = d, s[++s[0]] = u;
    ll i, x, z = d;
    for (i = 0; i < g[u].size(); i++)
    {
        x = g[u][i].first;
        if (l[x] == -1) d = dfs(g, x, d + 1, s, a, l);
        if (a[x] == -1) l[u] = min(l[u], l[x]);
    }
    if (l[u] == z) while (a[u] == -1) a[s[s[0]--]] = u;
    return d;
}

void scc(vvii& g, ll *a)
{
    ll i, n = g.size(), s[n + 1], l[n];
    for (i = 0, s[0] = 0; i < n; i++) l[i] = a[i] = -1;
    for (i = 0; i < n; i++) if (l[i] == -1) dfs(g, i, 0, s, a, l);
}

void bellman_ford(vvii& g, vi& s, vi& d, vi& a)
{
    ll i, j, k, m = s.size(), x, w, q[3 + 2*m*m], p[3 + 2*m*m];
    q[0] = q[1] = p[0] = p[1] = 2;
    for (i = 0; i < m; i++)
        d[s[i]] = 0, a[s[i]] = 1, q[q[1]++] = s[i], p[p[1]++] = 0;
    while (q[0] != q[1])
    {
        i = q[q[0]++], j = p[p[0]++], a[i] = 0;
        for (k = 0; k < g[i].size(); k++) if (a[g[i][k].first] != -1)
        {
            x = g[i][k].first, w = g[i][k].second;
            if (d[x] != -INF && d[i] + w < d[x])
            {
                d[x] = j < m ? d[i] + w : -INF;
                if (!a[x]) a[x] = 1, q[q[1]++] = x, p[p[1]++] = j + 1;
            }
        }
    }
}

vi all_nodes_on_negative_cycle(vvii& g)
{
    ll i, j, n = g.size(), a[n];
    vi r(n), d(n), v(n);
    vvi s(n);
    scc(g, a);
    for (i = 0; i < n; i++) s[a[i]].push_back(i), v[i] = -1;
    for (i = 0; i < n; i++)
    {
        bellman_ford(g, s[i], d, v);
        for (j = 0; j < s[i].size(); j++) r[s[i][j]] = (d[s[i][j]] != -INF);
        for (j = 0; j < s[i].size(); j++) v[s[i][j]] = -1;
    }
    return r;
}

vvi johnson(vvii &g)
{
    ll i, j, n = g.size(), x, w;
    vi s, b = all_nodes_on_negative_cycle(g), c(n, -1), h(n, -INF);
    for (i = 0; i < n; i++) if (b[i]) s.push_back(i);
    bellman_ford(g, s, h, c);
    vvi d(n);
    vvii q(2*n);
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)
    {
        x = g[i][j].first, w = g[i][j].second;
        if (h[x] == -INF) q[i].push_back(ii(x + n, 0));
        else if (h[i] != -INF) q[i].push_back(ii(x, w + h[i] - h[x]));
        q[i + n].push_back(ii(x + n, 0));
    }
    for (i = 0; i < n; i++) d[i] = dijkstra(q, i);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        if (d[i][j] != INF) d[i][j] = d[i][j] - h[i] + h[j];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        if (d[i][j + n] != INF) d[i][j] = -INF;
    for (i = 0; i < n; i++) d[i].resize(n);
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

    vvi d = johnson(g);
    
    // process queries
    for (ll i = 0; i < Q; i++) {
      ll src, sink;
      cin >> src >> sink;
      src--; sink--;

      if (d[src][sink] == INF) printf("engin leid\n");
      else if (d[src][sink] == -INF) printf("nogu hlytt\n");
      else printf("%lld\n", d[src][sink]);
    }

    return 0;
}
