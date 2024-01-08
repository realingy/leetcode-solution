
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

    # leetcode572 另一棵树的子树
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def dfs(n1: Optional[TreeNode], n2: Optional[TreeNode]) -> bool:
            if n1 is None: return False
            return self.check(n1, n2) or dfs(n1.left, n2) or dfs(n1.right, n2)
        return dfs(root, subRoot)

    # leetcode2925 在树上执行操作以后得到的最大分数
    def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
        # 正难则反
        # 将问题转换成求损失的最小值(保证数是健康树的前提下)
        g = [[] for _ in values]
        g[0].append(-1) # 防止根节点被误判为叶子
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)
        
        # 树形DP不需要加cache
        def dfs(x: int, d: int) -> int:
            if len(g[x]) == 1: # 叶子，说明非叶子节点都被包括了, 叶子节点一定要损失
                return values[x]
            # 选：损失 不选：不损失
            loss = values[x]
            loss2 = 0
            for y in g[x]:
                if y != d: # 不能往根节点方向递归(不能向上递归)
                    loss2 += dfs(y, x)
            return min(loss, loss2)
        
        return sum(values) - dfs(0, -1)
    
    # leetcode199 二叉树的右视图
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # 先处理右子树，后处理左子树
        ans = []
        def f(node, depth):
            if node is None:
                return
            if depth == len(ans):
                ans.append(node.val)
            f(node.right, depth+1)
            f(node.left, depth+1)
        f(root, 0)
        return ans

    # leetcode98 验证二叉搜索树
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def check(node, left, right):
            if node is None:
                return True
            x = node.val
            return left < x < right and check(node.left, left, x)  and check(node.right, x, right)
        return check(root, -inf, inf)