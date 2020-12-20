class Heap:
    def __init__(self):
        self.heapList = [0]
        self.size = 0

    def parent(self, index):
        """
        Parent will be at math.floor(index/2). Since integer
        division simulates the floor function, we don't expliocitly use it.
        """
        return index // 2

    def leftChild(self, index):
        """return index of leftchild. """
        return 2 * index

    def rightChild(self, index):
        """return index of rightchild. """
        return 2 * index + 1

    def getMax(self):
        """Root is the maxVal in MaxHeap."""
        if self.size == 0:
            return -1
        return self.heapList[1]

    def getMin(self):
        """Root is the minVal in MinHeap."""
        if self.size == 0:
            return -1
        return self.heapList[1]

    def percolate_down(self, i):
        while (i * 2) <= self.size:
            minimum_child = self.minChild(i)
            if self.heapList[i] > self.heapList[minimum_child]:
                tmp = self.heapList[i]
                self.heapList[i] = self.heapList[minimum_child]
                self.heapList[minimum_child] = tmp
            i = minimum_child

    def minChild(self, i):
        if i * 2 + 1 > self.size:
            return i * 2
        else:
            if self.heapList[i * 2] < self.heapList[i * 2 + 1]:
                return i * 2
            else:
                return i * 2 + 1

    def percolate_up(self, i):
        while i // 2 > 0:
            if self.heapList[i] < self.heapList[i // 2]:
                self.heapList[i // 2], self.heapList[i] = (
                    self.heapList[i],
                    self.heapList[i // 2],
                )
            i //= 2

    def delete_max(self):
        retval = self.heapList[1]
        self.heapList[1] = self.heapList[self.size]
        self.size -= 1
        self.heapList.pop()
        self.percolate_down(1)
        return retval

    def delete_min(self):
        retval = self.heapList[1]
        self.heapList[1] = self.heapList[self.size]
        self.size -= 1
        self.heapList.pop()
        self.percolate_down(1)
        return retval

    def insert(self, key):
        self.heapList.append(key)
        self.size += 1
        self.percolate_up(self.size)

    def buildHeap(self, A):
        i = len(A) // 2
        self.size = len(A)
        self.heapList = [0] + A[:]
        while i > 0:
            self.percolate_down(i)
            i -= 1


if __name__ == "__main__":
    h = Heap()
    data = [3, 1, 4, 6, 5, 9, 7, 8]
    h.buildHeap(data)
    print(h.size)
    print(h.parent(3))
    print(h.leftChild(2))
    print(h.rightChild(5))
    print(h.getMin())
    print(h.delete_min())
    h.insert(2)
    print(h.heapList)
