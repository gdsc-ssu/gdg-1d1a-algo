# 프로그래머스 - 모두 0으로 만들기 (DFS)

import sys
from collections import defaultdict
sys.setrecursionlimit(10 ** 6)

result = 0
def solution(a, edges):
    if sum(a) != 0:
        return -1
        
    graph = defaultdict(list)
    for node_a, node_b in edges:
        graph[node_a].append(node_b)
        graph[node_b].append(node_a)
        
    def dfs(child, parent, graph, a):
        global result
        for c in graph[child]:
            if c != parent:
                dfs(c, child, graph, a)
        a[parent] += a[child]
        result += abs(a[child])
        
    dfs(0, 0, graph, a)
    return result