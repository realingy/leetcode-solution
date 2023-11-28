
class LeetArray:
    # leetcode1763 最长的美好子字符串
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2:
            return ""
        
        for i,c in enumerate(s):
            if any([c.upper() not in s, c.lower() not in s]):
                return max(self.longestNiceSubstring(s[:i]), self.longestNiceSubstring(s[i+1:]), key = len)
        return s

    # leetcode1876 长度为三且各字符不同的子字符串
    def countGoodSubstrings(self, s: str) -> int:
        if len(s) < 3:
            return 0 

        cnt = [0] * 26
        repeat = False
        for i in range (0, 3):
            idx = ord(s[i]) - ord('a')
            if cnt[idx] > 0:
                repeat = True
            cnt[idx] += 1

        res = 0
        if False == repeat:
            res += 1

        n = len(s)
        for i in range (1, n - 2):
            idx0 = ord(s[i - 1]) - ord('a')
            idx1 = ord(s[i]) - ord('a')
            idx2 = ord(s[i + 1]) - ord('a')
            idx3 = ord(s[i + 2]) - ord('a')
            cnt[idx0] -= 1
            cnt[idx3] += 1
            if 1 == cnt[idx1] and 1 == cnt[idx2] and 1 == cnt[idx3]:
                res += 1

        return res

    # leetcode485 最大连续1的个数
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        l = r = 0
        res = 0
        while l < len(nums) and r < len(nums):
            while l < len(nums) and 1 != nums[l]:
                l += 1
            r = l
            while r < len(nums) and 1 == nums[r]:
                r += 1
            res = max(res, r - l)
            l = r
        return res

    # leetcode1984 学生分数的最小差值
    def minimumDifference(self, nums: List[int], k: int) -> int:
        # 排序
        new_nums = sorted(nums)
        n = len(new_nums)
        res = inf
        for i in range (0, n - k + 1):
            res = min(res, new_nums[i+k-1]-new_nums[i])
        return res

    def takeCharacters(self, s: str, k: int) -> int:
      n = len(s)
      if(n < 3 * k):
        return -1
      j = n
      cnt = Counter()
      while cnt['a'] <  k or cnt['b'] < k or cnt['c'] < k:
        if(j == 0): 
          return -1
        j -= 1
        cnt[s[j]] += 1
      
      res = n - j
      for i, ch in enumerate(s):
        cnt[ch] += 1
        while(j < n and cnt[s[j]] > k):
          cnt[s[j]] -= 1
          j += 1
        res = min(res, i + 1 + n - j)
        if j == n:
          break
      return res

    # leetcode2521 数组乘积中的不同质因数数目
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        s = set()
        for x in nums:
            i = 2
            while i * i <= x:
                if 0 == x % i:
                    s.add(i)
                    while 0 == x % i:
                        x //= i
                i += 1
            if x > 1: s.add(x)
        return len(s)

    # leetcode2522 将字符串分割成值不超过 K 的子字符串
    def minimumPartition(self, s: str, k: int) -> int:
        res = 1
        x = 0
        for ch in s:
            i = ch - 'a'
            if(i > k): return -1
            x = x * 10 + i
            if x > k: 
                res += 1
                x = i
        return res



s = 'abcddf'
la = LeetArray()
len = la.countGoodSubstrings(s)


    
