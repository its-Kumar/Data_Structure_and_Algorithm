class BinaryTreeNode:
    def __init__(self, data=None):
        self.left = None
        self.data = data
        self.right = None

    def __str__(self):
        return f"Node[{self.data}]"

    def get_left(self):
        return self.left

    def get_right(self):
        return self.right

    def get_data(self):
        return self.data

    def set_data(self, data):
        self.data = data


# Traversal

# Preorder


def preorder_recursive(root):
    """Print preorder traversal of tree with recursion"""
    if root:
        print(root.data, end="  ")
        preorder_recursive(root.left)
        preorder_recursive(root.right)


def preorder(root):
    """Print preorder traversal of tree without recursion"""
    if not root:
        print("Tree is Empty")
        return
    stack = []
    stack.append(root)
    while stack:
        node = stack.pop()
        print(node.data, end="  ")
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    print()


# Inorder


def inorder_recursive(root):
    """Print inorder traversal of tree with recursion"""
    if root:
        inorder_recursive(root.left)
        print(root.data, end="  ")
        inorder_recursive(root.right)


def inorder(root):
    """Print inorder traversal of tree"""
    if not root:
        print("Tree is Empty.")
        return
    stack = []
    node = root
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            print(node.data, end="  ")
            node = node.right
    print()


# Postorder


def postorder_recursive(root):
    """Print postorder traversal of tree with recursion"""
    if root:
        postorder_recursive(root.left)
        postorder_recursive(root.right)
        print(root.data, end="  ")


def postorder(root):
    """Print postorder traversal of tree"""
    if not root:
        print("Tree is Empty.")
        return
    stack = []
    node = root
    visited = set()
    while stack or node:
        if node:
            stack.append(node)
            node = node.left

        else:
            node = stack.pop()
            if node.right and not (node.right in visited):
                stack.append(node)
                node = node.right
            else:
                visited.add(node)
                print(node.data, end="  ")
                node = None
    print()


# Levelorder
def levelorder(root):
    """Print levelorder traversal of tree"""
    h = height(root)
    for i in range(1, h + 1):
        print_level(root, i)


def print_level(root, level):
    """print Single level"""
    if not root:
        return
    if level == 1:
        print(root.data, end="  ")
    elif level > 1:
        print_level(root.left, level - 1)
        print_level(root.right, level - 1)


def height(root):
    """return height of the tree"""
    if not root:
        return 0
    lheight = height(root.left)
    rheight = height(root.right)
    if lheight > rheight:
        return lheight + 1
    else:
        return rheight + 1


def display_tree(root, level):
    if root != None:
        display_tree(root.right, level + 1)
        print()
        for i in range(level):
            print("\t", end="")
        print(root.data, end="")
        display_tree(root.left, level + 1)


def create_BinaryTree(inor, preor, inStart, inEnd):
    """
    Construct Binary tree from inorder and preorder.\n
    return root of the tree.
    \n
    Argument:\n
    inor - inorder of the tree\n
    preor- preorder of the tree

    """
    if inStart > inEnd:
        return
    temp = BinaryTreeNode(preor[create_BinaryTree.index])
    create_BinaryTree.index += 1

    if inStart == inEnd:
        return temp

    for i in range(inStart, inEnd + 1):
        if inor[i] == temp.data:
            index = i

    temp.left = create_BinaryTree(inor, preor, inStart, index - 1)
    temp.right = create_BinaryTree(inor, preor, index + 1, inEnd)
    return temp


def create_Treeby_level(root, levelor, i, n):
    """
    create binary tree form level order traversal.\n
    return root of the tree.
    \n
    Arguments:\n
    root -      root of the tree\n
    levelor -   levelorder of the tree\n
    i -         starting index of 'levelor'\n
    n -         size of 'levelor'\n
    """
    if i < n:
        temp = BinaryTreeNode(levelor[i])
        root = temp

        root.left = create_Treeby_level(root.left, levelor, 2 * i + 1, n)
        root.right = create_Treeby_level(root.right, levelor, 2 * i + 2, n)
    return root


if __name__ == "__main__":
    root = BinaryTreeNode(1)
    root.left = BinaryTreeNode(2)
    root.right = BinaryTreeNode(3)
    root.left.left = BinaryTreeNode(4)
    root.left.right = BinaryTreeNode(5)

    # preorder_recursive(root)
    preorder(root)
    print()
    # inorder_recursive(root)
    inorder(root)
    print()
    # postorder_recursive(root)
    postorder(root)
    print()
    # levelorder(root)
    # display_tree(root, 0)
    t2 = None
    t2 = create_Treeby_level(t2, [1, 2, 3, 4, 5, 6, 7, 8, 9], 0, 9)
    display_tree(t2, 0)
    t3 = None
    inor = ["D", "B", "E", "A", "F", "C"]
    preor = ["A", "B", "D", "E", "C", "F"]
    # Static Variable
    create_BinaryTree.index = 0
    t3 = create_BinaryTree(inor, preor, 0, len(inor) - 1)
    display_tree(t3, 0)
