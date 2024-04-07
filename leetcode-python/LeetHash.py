
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

    def maxFrequencyElements(self, nums: List[int]) -> int:
        # 三次遍历
        """
        cnt = Counter(nums)
        max_cnt = max(cnt.values())
        ans = 0
        for c in cnt.values():
            if c == max_cnt:
                ans += max_cnt
        return ans
        """

        # 两次遍历
        """
        cnt = Counter(nums)
        max_cnt = 0
        ans = 0
        for c in cnt.values():
            if c > max_cnt:
              max_cnt = c
              ans = max_cnt
            elif c == max_cnt:
              ans += c
        return ans
        """

        # 一次遍历 O(n)
        cnt = Counter()
        max_cnt = 0
        ans = 0
        for x in nums:
            cnt[x] += 1
            c = cnt[x]
            if c > max_cnt:
              max_cnt = ans = c
            elif c == max_cnt:
              ans += c
        return ans

