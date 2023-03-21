import math

def distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

def prim(n, x, y):
    visited = [False] * n
    distances = [float('inf')] * n
    distances[0] = 0
    total_distance = 0
    
    for _ in range(n):
        min_distance = float('inf')
        min_index = -1
        for i in range(n):
            if not visited[i] and distances[i] < min_distance:
                min_distance = distances[i]
                min_index = i
        visited[min_index] = True
        total_distance += min_distance
        
        for i in range(n):
            if not visited[i]:
                d = distance(x[min_index], y[min_index], x[i], y[i])
                distances[i] = min(distances[i], d)
    
    return total_distance

if __name
num_cases = int(input())

for i in range(num_cases):
    input()
    n = int(input())
    x = []
    y = []
    for j in range(n):
        xj, yj = map(float, input().split())
        x.append(xj)
        y.append(yj)
    
    print("{:.2f}".format(prim(n, x, y)))
    if i < num_cases - 1:
      print()
