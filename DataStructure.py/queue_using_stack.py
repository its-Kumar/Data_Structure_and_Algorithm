from Stack import Stack


class Queue(object):
    """Queue implementation using stcaks

    Args:
        size (int): size of the queue
    """

    def __init__(self, size=10):
        self.s1 = Stack(size)
        self.s2 = Stack(size)

    def is_empty(self):
        return self.s1.is_empty()

    def is_full(self):
        return self.s1.is_full()

    def enqueue(self, val):
        """Enqueue operation of queue

        Args:
            val (any): element to insert
        """
        if self.is_full():
            print("Queue is full")
            return
        self.s1.push(val)

    def dequeue(self):
        """
        Dequque operation of queue
        """
        if self.is_empty():
            print("Queue is Empty")
            return

        # move elements from stack 1 to stack 2
        while(not self.s1.is_empty()):
            val = self.s1.pop()
            self.s2.push(val)

        # store the value to return
        val = self.s2.pop()

        # move elements back to stack 1
        while (not self.s2.is_empty()):
            self.s1.push(self.s2.pop())
        return val

    def display(self):
        """
        Display/print the queue
        """
        print(self.s1.stk)


if __name__ == "__main__":
    q = Queue()
    while True:
        print("Queue Implementation using stack")
        print("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            val = input("Enter value to insert: ")
            q.enqueue(val)
        elif choice == 2:
            print(q.dequeue())
        elif choice == 3:
            print("queue is: ")
            q.display()
        else:
            break
