class Node:
    """
    Node class to represent a node of link list.
    """

    def __init__(self, data=None):
        self.data = data
        self.next = None

    def set_data(self, data):
        self.data = data

    def get_data(self):
        return self.data

    def set_next(self, next):
        self.next = next

    def get_next(self):
        return self.next

    def has_next(self):
        return self.next != None

    def __str__(self):
        return f"Node[{self.data}]"

class CircularLinkedList:
    def __init__(self, head=None):
        self.head = head

    def length(self):
        current = self.head
        if current == None:
            return 0
        count = 1
        current = current.next
        while current != self.head:
            current = current.next
            count += 1
        return count

    def print(self):
        current = self.head
        if current == None:
            print("List is empty")
        else:
            while True: 
                print(current.data, end="  ")
                current = current.next
                if current == self.head:
                    break


    def insert_atBegining(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
            new_node.next = new_node
        else:
            current = self.head
            while current.next != self.head:
                current = current.next
            new_node.next = self.head
            current.next = new_node
            self.head = new_node

    def insert_atEnd(self, data):
        new_node = Node(data)
        new_node.next = new_node
        if self.head == None:
            self.head = new_node
            return
        current = self.head
        while current.next != self.head:
            current = current.next
        new_node.next = self.head
        current.next = new_node

    def delete_firstNode(self):
        current = self.head
        if current == None:
            print("List Empty")
            return None
        if self.head.next == self.head:
            self.head = None
            return
        while current.next != self.head:
            current = current.next
        current.next = self.head.next
        self.head = self.head.next

    def delete_lastNode(self):
        if self.head == None:
            print("List is empty")
            return None
        if self.head.next == self.head:
            self.head = None
            return
        current = self.head
        temp = self.head
        while current.next != self.head:
            temp = current
            current = current.next
        temp.next = current.next


if __name__ == "__main__":
    print("Singly Link List")
    lst = CircularLinkedList()
    while True:
        print("\n1. View/print Link List")
        print("2. Insert at begining")
        print("3. Insert at end")
        print("4. Delete first node")
        print("5. Delete last node")
        print("6. Count Nodes")
        print("0. Exit")
        choice = int(input("Enter Your choice: "))
        if choice == 0:
            break
        elif choice == 1:
            lst.print()
        elif choice == 2:
            data = input("Enter data to insert: ")
            lst.insert_atBegining(data)
        elif choice == 3:
            data = input("Enter data to insert: ")
            lst.insert_atEnd(data)
        elif choice == 4:
            print(lst.delete_firstNode())
        elif choice == 5:
            print(lst.delete_lastNode())
        elif choice == 6:
            print(lst.length())
        else:
            print("Enter a valid choice: ")
