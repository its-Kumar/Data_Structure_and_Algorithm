class AVLNode:
    def __init__(self, data, left=None, right=None, balanceFactor=0):
        self.left = left
        self.data = data
        self.right = right
        self.balanceFactor = balanceFactor


class AVL:
    def __init__(self, root=None):
        self.root = root

    def height(self, root):
        if not root:
            return 0
        lheight = self.height(self.root.left)
        rheight = self.height(self.root.right)
        if lheight > rheight:
            return lheight + 1
        else:
            return rheight + 1

    def single_leftRotate(self, root):
        w = root.left
        root.left = w.right
        w.right = root
        return w

    def single_rightRotation(self, root):
        x = root.right
        root.right = x.left
        x.left = root
        return x

    def leftRight_rotate(self, root):
        x = root.left
        if x.balanceFactor == -1:
            root.balanceFactor = 0
            x.balanceFactor = 0
            root = self.single_leftRotate(root)
        else:
            y = x.left
            if y.balanceFactor == -1:
                root.balanceFactor = 1
                x.balanceFactor = 0
            elif y.balanceFactor == 0:
                root.balanceFactor = 0
                x.balanceFactor = 0
            else:
                root.balanceFactor = 0
                x.balanceFactor = -1
            y.balanceFactor = 0
            root.left = self.single_rightRotation(x)
            root = self.single_leftRotate(root)
        return root

    def rightLeft_rotate(self, root):
        x = root.right
        if x.balanceFactor == 1:
            root.balanceFactor = 0
            x.balanceFactor = 0
            root = self.single_rightRotation(root)
        else:
            y = x.left
            if y.balanceFactor == -1:
                root.balanceFactor = 0
                x.balanceFactor = 1
            elif y.balanceFactor == 0:
                root.balanceFactor = 0
                x.balanceFactor = 0
            else:
                root.balanceFactor = -1
                x.balanceFactor = 0
            y.balanceFactor = 0
            root.left = self.single_leftRotate(x)
            root = self.single_rightRotation(root)
        return root

    def insert(self, data):
        new_node = AVLNode(data)
        [self.root, taller] = self.recInsertAVL(self.root, new_node)

    def recInsertAVL(self, root, new_node):
        if not root:
            root = new_node
            root.balanceFactor = 0
            taller = True
        elif new_node.data < root.data:
            (root.left, taller) = self.recInsertAVL(root.left, new_node)
            if taller:
                if root.balanceFactor == 0:
                    root.balanceFactor = -1
                elif root.balanceFactor == 1:
                    root.balanceFactor = 0
                    taller = False
                else:
                    root = self.rightLeft_rotate(root)
                    taller = False
            else:
                (root.right, taller) = self.recInsertAVL(root.right, new_node)
                if taller:
                    if root.balanceFactor == -1:
                        root.balanceFactor = 0
                        taller = False
                    elif root.balanceFactor == 0:
                        root.balanceFactor = 1
                    else:
                        root = self.leftRight_rotate(root)
                        taller = False
            return root, taller

    def inOrderPrint(self):
        self.recInorder(self.root)

    def recInorder(self, root):
        if root:
            self.recInorder(root.left)
            print(root.data, end="  ")
            self.recInorder(root.right)


if __name__ == "__main__":
    avl = AVL()
    data = [3, 1, 9, 6, 0, 11, 2, 5, 4]

    for i in data:
        avl.insert(i)
    avl.inOrderPrint()
    print("Height = ", avl.height())
