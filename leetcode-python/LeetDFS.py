MOD = 10 ** 9 + 7

class LeetDFS:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for i, j in edges:
            g[i].append(j)
            g[j].append(i)
        
        res = total = cnt = 0
        vis = [False] * n
        def dfs(x: int) -> None:
            vis[x] = True
            nonlocal cnt
            cnt += 1
            for y in g[x]:
                if not vis[y]:
                    dfs(y)

        for i in range(n):
            if not vis[i]:
                cnt = 0
                dfs(i)
                res += cnt * total
                total += cnt
        
        return res

    # leetcode2318 不同骰子序列的数目
    def distinctSequences(self, n: int) -> int:
        @cache
        def dfs(n: int, last: int, last2: int) -> int:
            if n == 0:
                return 1
            res = 0
            for cur in range(1, 7):
                if cur != last and cur != last2 and gcd(cur, last) == 1:
                    res += dfs(n-1, cur, last)
            return res % MOD
        return dfs(n, 7, 7)

    # capcity: 背包容量
    # w[i]: 第i个物品的体积
    # v[i]: 第i个物品的价值
    # 返回：所选物品体积和不超过capcity的前提下，所能得到的最大价值
    def f(capcity: int, w: List[int], v: List[int]) -> int:
        n = len(w)
        @cache
        def dfs(i, c):
            if i < 0:
                return 0
            if c < w[i]:
                return dfs(i-1, c)
            return max(dfs(i-1, c), dfs(i-1, c-w[i] + v[i]))
        return dfs(n-1, capcity)

    # leetcode494 目标和
    def findTargetSumWays(self, nums: List[int], t: int) -> int:
        # 正号的数的和为p，nums的总和为s，那么负号数的和就是(s-p)，
        # 所以有 p - (s - p) = t
        # p = (s+t) / 2
        # 问题就转换成找某一些数的和等于(s+t)/2的问题
        n = len(nums)
        sm = sum(nums)
        if (sm + t) % 2 != 0 or (sm + t) < 0: return 0
        p = (sm + t) / 2

        @cache
        def dfs(i, n):
            if i < 0:
                return 1 if n == 0 else 0 
            if nums[i] > n:
                return dfs(i-1, n) # 不能选
            return dfs(i-1, n) + dfs(i-1, n - nums[i]) # 选或者不选两种情况互相独立，直接相加

        return dfs(n-1, p)

    # leetcode198 打家劫舍
    def rob(self, nums: List[int]) -> int:
        # DFS回溯问题三问：
        # 1、当前操作：枚举第i个房子选/不选
        # 2、子问题：从前i个房子中得到的最大金额
        # 3、下一个问题：
        #       选当前房子，从i-2个房间得到的最大金额和；
        #       不选当前房子，从前i-1个房子中得到的最大金额和。

        # 记忆化搜索
        # @cache
        # def dfs(i):
        #     if i < 0:
        #         return 0
        #     return max(dfs(i-1), dfs(i-2)+nums[i])
        # return dfs(len(nums)-1)

        # 递推
        n = len(nums)
        f = [0](n+2)
        for i, x in enumerate(nums):
            f[i+2] = max(f[i+1], f[i] + x)
        return f[n+1]

        # 动态规划
        n = len(nums)
        if n < 2: return nums[0]
        if n < 3: return max(nums[0], nums[1])
        a = nums[0]
        b = max(nums[0], nums[1])
        res = 0
        for i in range(2, n):
            res = max(a+nums[i], b)
            a = b
            b = res # 这是重点
        return res

    # leetcode322 零钱兑换
    def coinChange(self, w: List[int], amount: int) -> int:
        # 完全背包问题：物品可以重复选，求体积不超capcity的最大价值和
        # 当前操作：不选，amount不变，选择一个，总值减小w[i]
        # 子问题：剩余总值为c时，从前i个中得到的最大价值和
        # 下一个问题：
        # 不选，剩余容量为c
        # 选了就可以继续选当前物品
        # dfs(i, c) = max(dfs(i-1, c), dfs(i, c - w[i]) + v[i])
        n = len(w)
        # @cache
        # def dfs(i, c):
        #     if i < 0:
        #         return 0 if c == 0 else inf
        #     if c < w[i]:
        #         return dfs(i-1, c) # 不能选
        #     return min(dfs(i-1, c), dfs(i, c - w[i]) + 1)
        # res = dfs(n-1, amount)
        # return res if res < inf else -1

        # 递推
        f = [[inf] * (amount+1) for _ in range(n+1)]
        f[0][0] = 0
        for i, x in enumerate(w):
            for c in range(amount+1):
                if c < w[i]:
                    f[i+1][c] = f[i][c]
                else:
                    f[i+1][c] = min(f[i][c], f[i+1][c-x]+1)
        res = f[n][amount]
        return res if res < inf else -1