class Node:
    def __init__(self, data):
        self.prev = None
        self.data = data
        self.next = None

    def __str__(self):
        return "Node[Data] = %s" % (self.data)


class DoublyLinkedList:
    def __init__(self, head=None):
        self.head = head

    # Traversal
    def display(self):
        ptr = self.head
        if ptr == None:
            print("Link List is empty..")
        else:
            while ptr != None:
                print(ptr.data, end="  ")
                ptr = ptr.next

    def count(self):
        count = 0
        ptr = self.head
        if ptr == None:
            print("Link List is empty..")
        else:
            while ptr != None:
                count += 1
                ptr = ptr.next
        return count

    # Insertion
    def insert_atBegining(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def insert_atLast(self, data):
        ptr = self.head
        new_node = Node(data)
        if ptr == None:
            self.head = new_node
        else:
            while ptr.next != None:
                ptr = ptr.next
            ptr.next = new_node
            new_node.prev = ptr

    def insert_atPosition(self, pos, data):
        l = self.count()
        if pos > l or pos < 0:
            print("Invalid position")
            return
        if pos == 0:
            self.insert_atBegining(data)
            return
        if pos == l:
            self.insert_atLast(data)
            return
        ptr = self.head
        count = 0
        new_node = Node(data)
        while count < pos - 1:
            count += 1
            ptr = ptr.next
        new_node.prev = ptr
        new_node.next = ptr.next
        ptr.next = new_node

    def delete_firstNode(self):
        if self.head == None:
            print("List is empty")
            return None
        ptr = self.head
        self.head = ptr.next
        self.head.prev = None
        return ptr.data

    def delete_lastNode(self):
        if self.head == None:
            print("List is empty")
            return None
        ptr = self.head
        while ptr.next != None:
            ptr = ptr.next
        ptr.prev.next = None
        return ptr.data

    def remove(self, data):
        if self.head == None:
            print("List is empty")
        else:
            ptr = self.head
            while (ptr.next != None) or (ptr.data != data):
                if ptr.data == data:
                    ptr.prev.next = ptr.next
                    ptr.next.prev = ptr.prev
                    return ptr.data
                else:
                    ptr = ptr.next
            print("The Value not present in the list")

    def delete_byPosition(self, pos):
        if self.head == None:
            print("List is empty")
        else:
            count = 0
            ptr = self.head
            if pos > self.count() or pos < 0:
                print("The position does not exist. Please enter a valid position")
            else:
                while ptr.next != None or count < pos:
                    count += 1
                    if pos == count:
                        ptr.prev.next = ptr.next
                        ptr.next.prev = ptr.prev
                        return ptr.data
                    else:
                        ptr = ptr.next

    def delete(self):
        self.head = None


if __name__ == "__main__":
    print("Doubly Link List")
    lst = DoublyLinkedList()
    while True:
        print("\n1. View/print Link List")
        print("2. Insert at begining")
        print("3. Insert at end")
        print("4. Insert at given position")
        print("5. Delete first node")
        print("6. Delete last node")
        print("7. Delete the given node")
        print("8. Delete the data")
        print("9. Delete whole list ")
        print("10. Count Nodes")
        print("0. Exit")
        choice = int(input("Enter Your choice: "))
        if choice == 0:
            break
        elif choice == 1:
            lst.display()
        elif choice == 2:
            data = input("Enter data to insert: ")
            lst.insert_atBegining(data)
        elif choice == 3:
            data = input("Enter data to insert: ")
            lst.insert_atLast(data)
        elif choice == 4:
            position = int(input("Enter position: "))
            data = input("Enter data to insert: ")
            lst.insert_atPosition(position, data)
        elif choice == 5:
            print(lst.delete_firstNode())
        elif choice == 6:
            print(lst.delete_lastNode())
        elif choice == 7:
            position = int(input("Enter position: "))
            print(lst.delete_byPosition(position))
        elif choice == 8:
            data = input("Enter data to delete: ")
            lst.remove(data)
        elif choice == 9:
            lst.delete()
        elif choice == 10:
            print(lst.count())
        else:
            print("Enter a valid choice: ")
