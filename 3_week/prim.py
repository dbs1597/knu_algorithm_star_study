

def prim(graph, start):
    # print("prim")
    visited = [1]
    
    # for i in range(len()):

def primx(graph, start_node):
    visited[start_node] = 1 # 방문 갱신
    candidate = graph[start_node] # 인접 간선 추출
    heapq.heapify(candidate) # 우선순위 큐 생성
    mst = [] # mst
    total_weight = 0 # 전체 가중치

    while candidate:
        weight, u, v = heapq.heappop(candidate) # 가중치가 가장 적은 간선 추출
        if visited[v] == 0: # 방문하지 않았다면
            visited[v] = 1 # 방문 갱신
            mst.append((u,v)) # mst 삽입
            total_weight += weight # 전체 가중치 갱신

            for edge in graph[v]: # 다음 인접 간선 탐색
                if visited[edge[2]] == 0: # 방문한 노드가 아니라면, (순환 방지)
                    heapq.heappush(candidate, edge) # 우선순위 큐에 edge 삽입


def kruskal():
    print("kruskal")

if __name__ == '__main__':
    vertex, edge = map(int, input().split(' '))

    graph = [[]]
    for i in range(vertex):
        graph.append([])

    for i in range(edge):
        vertex1, vertex2, weight = map(int, input().split(' '))
        graph[vertex1].append([vertex2, weight])
        graph[vertex2].append([vertex1, weight])
        # print(graph)

    primx(graph, 1)


