class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False
        if self.rank[px] < self.rank[py]:
            self.parent[px] = py
        elif self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[px] = py
            self.rank[py] += 1
        return True

def kruskal(n, edges):
    edges = sorted(edges, key=lambda x: x[2])
    uf = UnionFind(n)
    mst_cost = 0
    mst_edges = []
    for u, v, w in edges:
        if uf.union(u, v):
            mst_cost += w
            mst_edges.append((min(u, v), max(u, v)))
    if len(mst_edges) != n-1:
        return "Impossible"
    return (mst_cost, mst_edges)

while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    edges = []
    for i in range(m):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))
    result = kruskal(n, edges)
    if result == "Impossible":
        print(result)
    else:
        mst_cost, mst_edges = result
        print(mst_cost)
        for u, v in sorted(mst_edges):
            print(u, v)
