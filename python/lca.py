class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None   

def findPath(root, path, k):
    if root is None:
        return False
    
    path.append(root.key)

    if root.key == k:
        return True

    if((root.left != None and findPath(root.left, path, k)) or 
        (root.right != None and findPath(root.right, path, k))):
        return True

    path.pop()
    return False

def findLCA(root, k1, k2):
    p1 = []
    p2 = []

    if(not findPath(root, p1, k1) or not findPath(root, p2, k2)):
        return -1

    i = 0
    while(i < len(p1) and i < len(p2)):
        if p2[i] != p1[i]:
            break
        i += 1

    return p1[i-1]

def buildTree():
    root = Node(0)
    root.left = Node(2)
    root.left.left = Node(8)
    root.left.right = Node(5)
    root.left.right.left = Node(6)
    root.left.right.right = Node(7)
    root.right = Node(1)
    root.right.right = Node(9)
    root.right.right.right = Node(3)
    root.right.right.right.right = Node(4)
    return root