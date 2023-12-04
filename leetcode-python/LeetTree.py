
class LeetTree:
    # leetcode1038 从二叉搜索树到更大和树
    def bstToGst(self, root: TreeNode) -> TreeNode:
        s = 0
        def dfs(node: TreeNode):
            if node is None:
                return
            dfs(node.right)
            nonlocal s
            s += node.val
            node.val = s
            dfs(node.left)
        dfs(root)
        return root

    # leetcode559 N叉树的最大深度
    def maxDepth(self, root: 'Node') -> int:
        def dfs(node: 'Node') -> int:
            if node is None:
                return 0
            d = 0
            for n in node.children:
                d = max(d, dfs(n))
            d += 1
            return d
        return dfs(root)

    # leetcode563 二叉树的坡度
    def findTilt(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(node: Optional[TreeNode]) -> int:
            if node is None:
                return 0
            l = dfs(node.left)
            r = dfs(node.right)
            res = node.val + l + r
            nonlocal ans
            ans += abs(l - r)
            return res
        dfs(root)
        return ans

    def check(self, n1: Optional[TreeNode], n2: Optional[TreeNode]) -> bool:
        if n1 is None and n2 is None: return True
        if n1 is None and n2 is not None: return False
        if n1 is not None and n2 is None: return False
        if n1.val != n2.val: return False
        return self.check(n1.left, n2.left) and self.check(n1.right, n2.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def dfs(n1: Optional[TreeNode], n2: Optional[TreeNode]) -> bool:
            if n1 is None: return False
            return self.check(n1, n2) or dfs(n1.left, n2) or dfs(n1.right, n2)
        return dfs(root, subRoot)
