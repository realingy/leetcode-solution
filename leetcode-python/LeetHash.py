
class LeetHash:
    # leetcode2453 摧毁一系列目标
    def destroyTargets(self, nums: List[int], space: int) -> int:
        cnt = defaultdict(int)
        for n in nums:
          cnt[n%space] += 1
        mx = -inf
        res = nums[0]
        for n in nums:
          c = cnt[n%space]
          if c == mx:
            res = min(res, n)
          elif c > mx:
            mx = c
            res = n            
        return res

