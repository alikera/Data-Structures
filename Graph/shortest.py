class Node:
    def __init__(self):
        self.adj = []
        
    def add_adj(self, adj):
        self.adj.append(adj)
        self.deg += 1

def add_edge(nodes, u, v):
    nodes[v].adj.append(u)
    nodes[u].adj.append(v)

def get_input(nodes):
    n = input()
    for i in range(int(n)+1):
        dum = Node()
        nodes.append(dum)
        
    for i in range (int(n) - 1):
        u, v=list(map(int,input().split()))
        add_edge(nodes, u, v)
        
    return nodes

def find_nodes(nodes, leaves, n):
    while n > 2:
        s = len(leaves)
        n = n-s
        for i in range (s):
            node = leaves.pop(0)
            adj_node = nodes[node].adj.pop()
            nodes[adj_node].adj.remove(node)
            if len(nodes[adj_node].adj) == 1:
                leaves.append(adj_node)
    return leaves
            


n = 0;
arr = []
nodes = get_input(arr)
n = len(nodes)

leaves = []
for i in range (n):
    if len(nodes[i].adj) == 1:
        leaves.append(i)
ans = find_nodes(nodes, leaves, n-1)
ans.sort()
for x in ans:
    print(x, end=" ")
