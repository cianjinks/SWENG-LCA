import unittest
import lca

# No strange edge cases
class SimpleTestCase(unittest.TestCase):
    def setUp(self) -> None:
        self.tree = lca.buildTree()

    def test(self):
        assert(lca.findLCA(self.tree, 6, 7) == 5)
        assert(lca.findLCA(self.tree, 8, 7) == 2)
        assert(lca.findLCA(self.tree, 8, 3) == 0)
        assert(lca.findLCA(self.tree, 9, 6) == 0)

# When root is None
class NoneTestCase(unittest.TestCase):
    def setUp(self) -> None:
        self.tree = None

    def test(self):
        assert(lca.findLCA(self.tree, 100, 2) == -1)
        assert(lca.findLCA(self.tree, 20, 1) == -1)

# LCA of same node with itself
class SameTestCase(unittest.TestCase):
    def setUp(self) -> None:
        self.tree = lca.buildTree()

    def test(self):
        assert(lca.findLCA(self.tree, 9, 9) == 9)
        assert(lca.findLCA(self.tree, 6, 6) == 6)
        assert(lca.findLCA(self.tree, 4, 4) == 4)
    
# If 3 is the parent of 4 what is the LCA of 3 and 4?
class ParentTestCase(unittest.TestCase):
    def setUp(self) -> None:
        self.tree = lca.buildTree()
    
    def test(self):
        assert(lca.findLCA(self.tree, 3, 4) == 3)
        assert(lca.findLCA(self.tree, 9, 3) == 9)

if __name__ == "__main__":
    unittest.main()