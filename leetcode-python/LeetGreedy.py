
class LeetGreedy:
    # leetcode1217 玩筹码
    def minCostToMoveChips(self, p: List[int]) -> int:
        # resolve 20231205
        c1 = c2 = 0
        for x in p:
            if 0 == x % 2: c2 += 1
            else: c1 += 1
        return min(c1, c2)

    # leetcode1221 分割平衡字符串
    def balancedStringSplit(self, s: str) -> int:
        # resolve 20231205
        res = 0
        c1 = c2 = 0
        for x in s:
            if 'R' == x: c1 += 1
            else: c2 += 1
            if c1 == c2:
                res += 1
                c1 = c2 = 0
        return res if res > 0 else 1
