from collections import deque


graph = {
    'A': ['B', 'D'],
    'B': ['C', 'F'],
    'C': ['E', 'G'],
    'D': ['F'],
    'E': [],
    'F': ['E'],
    'G': ['E']
}


for node in graph:
    graph[node].sort()

visited = set()
queue = deque()
bfs_order = []

start_node = 'A'
queue.append(start_node)
visited.add(start_node)

while queue:
    node = queue.popleft()
    bfs_order.append(node)

    for neighbor in graph[node]:
        if neighbor not in visited:
            visited.add(neighbor)
            queue.append(neighbor)

print("BFS Traversal Order:")
print(" ".join(bfs_order))

with open("bfs_results.txt", "w") as file:
    file.write("BFS Traversal Order:\n")
    file.write(" ".join(bfs_order))

print("Output saved to bfs_results.txt")

"""
OUTPUT
BFS Traversal Order:
A B D C F E G
Output saved to bfs_results.txt
"""