class Stack(object):
    """Stack implementation using array implementation.

    Args:
        limit (int): size of the stack
    """

    def __init__(self, limit=10):
        self.limit = limit
        self.stk = []

    def is_empty(self):
        """Check for the stcak to be empty
        """
        return self.stk == []

    def is_full(self):
        """Check for the stcak to be full
        """
        return self.length() == self.limit

    def length(self):
        """return the size of the stack
        """
        return len(self.stk)

    def push(self, item):
        """push operation of stack

        Args:
            item (any): element to insert
        """
        if self.length() >= self.limit:
            print("Stack OverFlow")
            return
        self.stk.append(item)
        print("Stack after push", self.stk)

    def pop(self):
        """Pop operation of stack

        Returns:
            value at top
        """
        if self.length() <= 0:
            print("Stack Underflow")
            return None
        return self.stk.pop()

    def peek(self):
        """Returns value at top of the stack
        """
        if self.length() <= 0:
            print("Stack Underflow")
            return None
        return self.stk[-1]

    def __str__(self):
        return f"Stack: {self.stk}"


if __name__ == "__main__":
    s = Stack()
    while True:
        print("\n1. View Stack")
        print("2. Push")
        print("3. Pop")
        print("4. Peek")
        print("5. Size of Stack")
        print("0. Exit")
        ch = int(input("Enter your choice"))
        if ch == 0:
            break
        elif ch == 1:
            print(s)
        elif ch == 2:
            value = input("Enter a value to push: ")
            s.push(value)
        elif ch == 3:
            print(s.pop())
        elif ch == 4:
            print(s.peek())
        elif ch == 5:
            print(s.length())
        else:
            print("Please Enter valid choice")
