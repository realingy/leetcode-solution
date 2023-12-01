
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

    # leetcode2486 追加字符以获得子序列
    def appendCharacters(self, s: str, t: str) -> int:
        i, n = 0, len(s)
        for j, ch in enumerate(t):
            while i < n and s[i] != ch:
                i += 1
            if i == n: return len(t) - j
            i += 1
        return 0

    # leetcode2488 统计中位数为 K 的子数组
    def countSubarrays(self, nums: List[int], k: int) -> int:
        idx = nums.index(k)
        n = len(nums)
        cnt = defaultdict(int)
        cnt[0] += 1
        x = 0
        for i in range (idx + 1, n):
            x += 1 if nums[i] > k else -1
            cnt[x] += 1
        
        x = 0
        res = cnt[0] + cnt[1]
        for i in range (idx - 1, -1, -1):
            x += -1 if nums[i] > k else 1
            res += cnt[x] + cnt[x+1]
        return res
    
    # leetcode2337 移动片段得到字符串
    def canChange(self, start: str, target: str) -> bool:
        # 性质1 字母需要一一对应
        if start.replace('_', '') != target.replace('_', ''):
            return False
        
        # 保证完性质1，下面就可以一一对应
        # 性质2 start[i] target[j]
        # L: i >= j R: i <= j
        j = 0
        for i, ch in enumerate(start):
            if ch == '_': continue
            while j < len(target) and target[j] == '_': j += 1
            if ch == 'L': 
                if i < j: return False
            else:
                if i > j: return False
            j += 1
        return True
        
    # leetcode2928 给小朋友们分糖果I
    # leetcode2929 给小朋友们分糖果II
    def distributeCandies(self, n: int, limit: int) -> int:
        def f(i: int) -> int:
            return i*(i-1) // 2 if i > 1 else 0
        return f(n+2) - 3*f(n - (limit+1) + 2) + 3*f(n - 2*(limit+1) + 2) - f(n - 3*(limit+1) + 2)

    # leetcode2930 重新排列后包含指定子字符串的字符串数目
    def stringCount(self, n: int) -> int:
        # dfs背包
        mod = 10**9 + 7
        def dfs(i: int, l: int, t: int, e: int) -> int:
            if i == 0:
                return 1 if l == t == e == 0 else 0
            res = dfs(i-1, 0, max(t-1, 0), e) + dfs(i-1, l, max(t-1, 0), e) + dfs(i-1, l, t, max(e-1, 0))
            res += dfs(i-1, l, t, e) * 23
            return res % mod

        return dfs(n, 1, 1, 2)


        # 容斥原理
        # mod = 10**9 + 7
        # return ( pow(26, n, mod) 
                # - pow(25, n-1, mod)*(75 + n)
                # + pow(24, n-1, mod)*(72 + 2 * n)
                # - pow(23, n-1, mod)*(23 + n) )% mod

    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # resolve 20231201
        # 出现在第一个位置就不是法官（是市民），出现在第二个位置，则统计信任此人的数量（假如不是市民）
        # citizen = [False] * n
        # cnt = [0] * n
        # for i in range(len(trust)):
            # citizen[trust[i][0] - 1] = True
            # if citizen[trust[i][1] - 1] == False:
                # cnt[trust[i][1] - 1] += 1
        # for i in range(n):
            # if citizen[i] == False and cnt[i] == n - 1:
                # return i + 1
        # return -1

        # resolve 20231201
        # 入度
        cnt = [0] * n
        for _, t in enumerate(trust):
            cnt[t[0]-1] -= 1
            cnt[t[1]-1] += 1
        for i in range(n):
            if cnt[i] == n - 1:
                return i + 1
        return -1
        
    # leetcode2843 统计对称整数的数目
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        res = 0
        for i in range(low, high+1):
            s = str(i)
            n = len(s)
            if n%2: continue
            m = n // 2
            # python库函数
            # if sum(map(int, s[:m])) == sum(map(int, s[m:])):
                # res += 1
            diff = 0
            for j in range(m):
                diff += int(s[i]) - int(s[i+m])
            if diff == 0:
                res += 1
        return res

    # leetcode2844 生成特殊数字的最少操作
    def minimumOperations(self, num: str) -> int:
        n = len(num)
        res = n
        if '0' in num:
            res -= 1
        def f(tail: str) -> int:
            i = num.rfind(tail[1])
            if i < 0: return n
            i = num.rfind(tail[0], 0, i)
            if i < 0: return n
            return n - i - 2
        return min(res, f("00"), f("25"), f("50"), f("75"))

    # leetcode2845 统计趣味子数组的数目
    def countInterestingSubarrays(self, nums: List[int], m: int, k: int) -> int:
        # 前缀和
        n = len(nums)
        pre = [0] * (n + 1)
        for i, x in enumerate(nums):
            pre[i+1] = pre[i] + (k == x%m) #根据策略计算拟合前缀和数组
        ans = 0
        cnt = Counter()
        for s in pre:
            ans += cnt[(s%m -k + m) % m]
            cnt[s%m] += 1
        return ans

    # leetcode2933 高访问员工
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        name2times = defaultdict(list)
        for name, s in access_times:
            t = int(s[:2]) * 60 + int(s[2:])
            name2times[name].append(t)
        ans = []
        for name, a in name2times.items():
            a.sort()
            for i in range(2, len(a)):
                if a[i] - a[i-2] < 60:
                    ans.append(name)
                    break
        return ans

s = 'abcddf'
la = LeetArray()
len = la.countGoodSubstrings(s)


    
