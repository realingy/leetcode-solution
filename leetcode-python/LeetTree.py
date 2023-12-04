
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






