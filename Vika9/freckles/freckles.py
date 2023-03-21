import math

# Euclidean distance
def euclid(x_1, y_1, x_2, y_2):
    return math.sqrt((x_1 - x_2)**2 + (y_1 - y_2)**2)

# Prim's algorithm for total weight of minimum
# spanning tree (i.e. length)
def prim(n, x, y):
    V = [False] * n    
    Dist = [float('inf')] * n
    Dist[0] = 0

    d_total = 0

    for _ in range(n):
        d_min = float('inf')
        i_min = -1

        for i in range(n):
            if not V[i] and Dist[i] < d_min:
                d_min = Dist[i]
                i_min = i

        V[i_min] = True
        d_total += d_min

        for i in range(n):
            if not V[i]:
                d = euclid(x[i_min], y[i_min], x[i], y[i])
                Dist[i] = min(Dist[i], d)

    return d_total 

if __name__ == "__main__":
    num_cases = int(input())

    for i in range(num_cases):
        input()
        n = int(input())
        x = []; y = []

        for j in range(n):
            xj, yj = map(float, input().split())
            x.append(xj); y.append(yj)
        
        print("{:.2f}".format(prim(n, x, y)))
        if i < num_cases - 1:
          print()
