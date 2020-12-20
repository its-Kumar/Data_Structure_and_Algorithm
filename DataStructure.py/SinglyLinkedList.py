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


class SinglyLinkedList(object):
    """
    SinglyLinkedList class to represent a singly linked list.
    """

    # Constructure

    def __init__(self, head=None):
        self.head = head

    # count nodes in linked list
    def length(self):
        current = self.head
        count = 0
        while current != None:
            count += 1
            current = current.get_next()
        return count

    # Print entire linked list
    def print(self):
        if self.head == None:
            print("List is empty....")
        else:
            current = self.head
            while current != None:
                print(current.get_data(), end="\t")
                current = current.get_next()

    # Insersion
    def insert_atBegining(self, data):
        new_node = Node(data)
        if self.length() == 0:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    def insert_atEnd(self, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
        else:
            current = self.head
            while current.get_next() != None:
                current = current.get_next()
            current.next = new_node

    def insert_atPosition(self, pos, data):
        l = self.length()
        if pos > l or pos < 0:
            print("Insertion is not possible..!!")
            return None
        if pos == 0:
            self.insert_atBegining(data)
        elif pos == l:
            self.insert_atEnd(data)
        else:
            new_node = Node(data)
            count = 0
            current = self.head
            while count < pos - 1:
                count += 1
                current = current.next
            new_node.next = current.next
            current.next = new_node

    # Deletion
    def delete_firstNode(self):
        if self.head == None:
            print("Deletion not possible")
            return None
        data = self.head.get_data()
        self.head = self.head.next
        return data

    def delete_lastNode(self):
        if self.head == None:
            print("Deletion not possible")
            return None
        current = self.head
        prev = self.head
        while current.next != None:
            prev = current
            current = current.next
        prev.next = None
        return current.data

    def remove(self, data):
        if self.head == None:
            print("List is empty")
        else:
            current = self.head
            prev = self.head
            while (current.next != None) or (current.data != data):
                if current.data == data:
                    prev.next = current.next
                    return current.data
                else:
                    prev = current
                    current = current.next
            print("The Value not present in the list")

    def delete_byPosition(self, pos):
        if self.head == None:
            print("List is empty")
        else:
            count = 0
            current = self.head
            prev = self.head
            if pos > self.length() or pos < 0:
                print("The position does not exist. Please enter a valid position")
            else:
                while current.next != None or count < pos:
                    count += 1
                    if pos == count:
                        prev.next = current.next
                        return current.data
                    else:
                        prev = current
                        current = current.next

    def delete(self):
        self.head = None


if __name__ == "__main__":
    print("Singly Link List")
    lst = SinglyLinkedList()
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
            lst.print()
        elif choice == 2:
            data = input("Enter data to insert: ")
            lst.insert_atBegining(data)
        elif choice == 3:
            data = input("Enter data to insert: ")
            lst.insert_atEnd(data)
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
            print(lst.length())
        else:
            print("Enter a valid choice: ")
