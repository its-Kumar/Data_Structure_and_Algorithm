import Queue


def dfs(G, currentVert, visited):
    visited[currentVert] = True
    print("traversal: " + currentVert.getVertexID())
    for nbr in currentVert.getConnections():
        if nbr not in visited:
            dfs(G, nbr, visited)


def DFSTraversal(G):
    visited = {}
    for currentVert in G:
        if currentVert not in visited:
            dfs(G, currentVert, visited)


def BFSTraversal(G, s):
    start = G.getVertex(s)
    start.setDistance(0)
    start.setPrevious(None)
    vertQueue = Queue()
    vertQueue.enQueue(start)
    while vertQueue.size > 0:
        currentVert = vertQueue.deQueue()
        print(currentVert.getVertexID())
        for nbr in currentVert.getConnections():
            if nbr.getColor == "White":
                nbr.setColor("Gray")
                nbr.setDistance(currentVert.getDistance() + 1)
                nbr.setPrevious(currentVert)
                vertQueue.enQueue(nbr)
            currentVert.setColor("Black")


def BFS(G):
    for v in G:
        if v.getColor() == "White":
            BFSTraversal(G, v.getVertexID())
