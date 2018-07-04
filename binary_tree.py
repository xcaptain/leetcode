# python binary tree
class BinaryNode:
    def __init__(self, value = None):
        self.value = value
        self.left = None
        self.right = None

    def add(self, val):
        if val <= self.value:
            if not self.left: # 左子树为空，直接设置左子树
                self.left = BinaryNode(val)
            else:
                self.left.add(val)
        else:
            if not self.right:
                self.right = BinaryNode(val)
            else:
                self.right.add(val)

class BinaryTree:
    def __init__(self):
        self.root = None

    def add(self, value):
        if self.root is None:
            self.root = BinaryNode(value)
        else:
            self.root.add(value)

    def __contains__(self, target):
        node = self.root
        while node:
            if target < node.value:
                node = node.left
            elif target > node.value:
                node = node.right
            else:
                return True
        return False

if __name__ == '__main__':
    t = BinaryTree()
    t.add(5)
    t.add(3)
    t.add(6)
    t.add(2)
    t.add(4)
    t.add(7)
    print(t.__contains__(3))
    print(t.__contains__(4))
    print(t.__contains__(1))
