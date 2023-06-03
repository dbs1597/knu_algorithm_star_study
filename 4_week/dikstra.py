import sys
from collections import defaultdict
from queue import PriorityQueue

input = sys.stdin.readline

vertex, edge = map(int, input().split(' '))

adj_matrix = [[11] * vertex for _ in range(vertex)]

for i in range(len(adj_matrix)):
    adj_matrix[i][i] = 0

length = vertex

# print(vertex, edge)

init = int(input())

# print(init)

# 입력받아서 그래프 만들기
for i in range(edge):
    vertex1, vertex2, weight = map(int, input().split(' '))
    adj_matrix[vertex1-1][vertex2-1] = weight

visited = [False]*length
visited[init] = True

distance_list = []

for i in range(length):
    distance_list.append(adj_matrix[init-1][i])
distance_list[init-1] = 0
print(distance_list)

def FindSmallestNode():
    min_dist = 11
    min_idx = -1

    for i in range(len(distance_list)):
        if not visited[i] and distance_list[i] < min_dist:
            min_dist = distance_list[i]
            min_idx = i

    return min_idx;    

def dikstra(init):

    queue = PriorityQueue()

    queue.put((init, 0))

    while(not queue.empty()):

        node = queue.get()[0]

        print("node", node)

        # node = distance_list.index(min(distance_list))

        # print(node)

        for i in range(length):
            if (adj_matrix[init][node] + adj_matrix[node][i]) < distance_list[i]:
                distance_list[i] = adj_matrix[init][node] + adj_matrix[node][i]
                queue.put((i, distance_list[i]))

        # print(distance_list)

    for i in range(length):
        if distance_list[i] == 11:
            print("INF")
        else:
            print(distance_list[i])

dikstra(init-1)