class Queue(object):
    """
    Queue Implementation: Circular Queue.
    """

    def __init__(self, limit=5):
        self.front = None
        self.rear = None
        self.limit = limit
        self.size = 0
        self.que = []

    def is_empty(self):
        return self.size <= 0

    def enQueue(self, item):
        if self.size >= self.limit:
            print("Queue Overflow..!!")
            return
        self.que.append(item)
        if self.front == None:
            self.front = self.rear = 0
        else:
            self.rear = self.size
        self.size += 1
        print("Queue after enQueue:", self.que)

    def deQueue(self):
        if self.size <= 0:
            print("Queue underflow..!!! ")
            return
        self.que.pop(0)
        self.size -= 1
        if self.size == 0:
            self.front = self.rear = None
        else:
            self.rear = self.size - 1
        print("Queue after deQueue: ", self.que)

    def queueRear(self):
        if self.rear == None:
            print("Sorry the queue is Empty.")
            raise IndexError
        return self.que[self.rear]

    def queueFront(self):
        if self.front == None:
            print("Sorry the queue is Empty.")
            raise IndexError
        return self.que[self.front]

    def size(self):
        return self.size


if __name__ == "__main__":
    q = Queue()
    q.enQueue("first")
    q.enQueue("second")
    q.enQueue("third")
    q.deQueue()
    print(q.queueFront())
    print(q.queueRear())
