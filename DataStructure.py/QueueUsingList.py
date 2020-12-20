class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __str__(self):
        return f"Node[{self.data}]"


class Queue(object):
    def __init__(self, data=None):
        self.front = None
        self.rear = None
        self.size = 0

    def size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def queueRear(self):
        if self.rear == None:
            print("Sorry the queue is Empty")
            raise IndexError
        return self.rear.data

    def queueFront(self):
        if self.front == None:
            print("Sorry the queue is empty")
            raise IndexError
        return self.front.data

    def enQueue(self, item):
        new_node = Node(item)
        if self.rear == None:
            self.front = self.rear = new_node
            return
        self.rear.next = new_node
        self.rear = new_node
        self.size += 1

    def deQueue(self):
        if self.is_empty():
            print("Queue is Empty")
            return
        temp = self.front
        self.front = temp.next
        self.size -= 1
        if self.front == None:
            self.rear = None
        return temp.data


if __name__ == "__main__":
    q = Queue()
    q.enQueue("first")
    q.enQueue("second")
    q.enQueue("third")
    print(q.deQueue())
    print(q.queueFront())
    print(q.queueRear())
