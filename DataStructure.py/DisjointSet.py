# MAKESET
class DisjointSet:
    def __init__(self, n):
        self.MAKESET(n)

    def MAKESET(self, n):
        self.S = [x for x in range(n)]

    # FIND
    def FIND(self, x):
        if S[x] == x:
            return x
        else:
            return FIND(x)

    # UNION
    def UNION(self, root1, root2):
        S[root1] = root2
