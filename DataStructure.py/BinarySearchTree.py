import BinaryTree as bt


class TreeNode:
    def __init__(self, data=None):
        self.left = None
        self.data = data
        self.right = None

    def __str__(self):
        return f"Node[{self.data}]"


def search(root, key: int):
    if not root:
        return None
    if root.data == key:
        return root
    elif root.data < key:
        return search(root.right, key)
    else:
        return search(root.left, key)


def min(root):
    if not root:
        return None
    while root.left != None:
        root = root.left
    return root


def max(root):
    if not root:
        return None
    while root.right != None:
        root = root.right
    return root


def insert(root, key: int):
    if not root:
        temp = TreeNode(key)
        root = temp
    elif key < root.data:
        root.left = insert(root.left, key)
    elif key > root.data:
        root.right = insert(root.right, key)
    else:
        print("Duplicate key....")
    return root


def delete(root, key: int):
    if not root:
        print("key is not found....")
        return root
    if root.data > key:
        root.left = delete(root.left, key)
    elif root.data < key:
        root.right = delete(root.right, key)
    else:
        if (root.left != None) and (root.right != None):
            temp = min(root.right)
            root.data = temp.data
            root.right = delete(root.right, temp.data)
        elif root.left != None:
            root = root.left
        elif root.right != None:
            root = root.right
        else:
            root = None
    return root


if __name__ == "__main__":
    root = None
    while True:
        print("\n1. Insert key")
        print("2. Delete key")
        print("3. Search key")
        print("4. Find Max key")
        print("5. Find Min key")
        print("6. Inorder")
        print("7. Preorder")
        print("8. Display Tree")
        print("0. Exit")
        ch = int(input("Enter your choice: "))
        if ch == 0:
            break
        elif ch == 1:
            value = int(input("Enter value to insert "))
            root = insert(root, value)
        elif ch == 2:
            value = int(input("Enter value to delete "))
            root = delete(root, value)
        elif ch == 3:
            value = int(input("Enter value to search "))
            ptr = search(root, value)
            if ptr:
                print("Search Successfull ")
            else:
                print("The value not found in the tree.")

        elif ch == 4:
            print("Max: ", max(root))
        elif ch == 5:
            print("Min: ", min(root))
        elif ch == 6:
            bt.inorder(root)
        elif ch == 7:
            bt.preorder(root)
        elif ch == 8:
            bt.display_tree(root, 0)

        else:
            print("Enter Valid Choice...")
