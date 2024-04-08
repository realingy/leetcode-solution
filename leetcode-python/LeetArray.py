
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

    # leetcode2934 最大化数组末位元素的最少操作次数
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        def f(last1: int, last2: int) -> int:
            res = 0
            for i in range(n-1):
                x = nums1[i]
                y = nums2[i]
                if x > last1 or y > last2:
                    if x > last2 or y > last1:
                        return n + 1 # 不满足条件
                    res += 1
            return res

        res = min(f(nums1[-1], nums2[-1]), f(nums2[-1], nums1[-1]) + 1)
        return res if res <= n else -1

    # leetcode2932 找出强数对的最大异或值I
    def maximumStrongPairXor(self, nums0: List[int]) -> int:
        nums = sorted(nums0)
        n = len(nums)
        res = -inf
        for i in range(n):
            j = i
            while j >= 0:
                if 2 * nums[j] >= nums[i]:
                    res = max(res, nums[j] ^ nums[i])
                j -= 1
        return res

    # leetcode421 数组中两个数的最大异或值
    def findMaximumXOR(self, nums: List[int]) -> int:
        high_bit = max(nums).bit_length() - 1
        res, mask = 0, 0
        for i in range(high_bit, -1, -1):
            seen = set()
            mask |= 1 << i
            new_res = res | (1 << i)
            for x in nums:
                x &= mask
                if new_res ^ x in seen:
                    res = new_res
                    break
                seen.add(x)
        return res

    # leetcode2865 美丽塔I
    def maximumSumOfHeights(self, a: List[int]) -> int:
        # 暴力
        res = 0
        n = len(a)
        for i, x in enumerate(a):
            s = mn = x
            for j in range(i-1, -1, -1):
                mn = min(mn, a[j])
                s += mn
            mn = x
            for j in range(i+1, n):
                mn = min(mn, a[j])
                s += mn
            res = max(res, s)
        return res

    # leetcode2866 美丽塔II
    def maximumSumOfHeights(self, a: List[int]) -> int:
        # 单调栈
        # 1、相同的数，只需要维护最左边的元素的下标
        # 2、用单调栈维护
        n = len(a)
        suf = [0] * (n + 1)
        st = [n]  # 哨兵
        s = 0
        for i in range(n - 1, -1, -1):
            x = a[i]
            while len(st) > 1 and x <= a[st[-1]]:
                j = st.pop()
                s -= a[j] * (st[-1] - j)  # 撤销之前加到 s 中的
            s += x * (st[-1] - i)  # 从 i 到 st[-1]-1 都是 x
            suf[i] = s
            st.append(i)

        ans = s
        st = [-1]  # 哨兵
        pre = 0
        for i, x in enumerate(a):
            while len(st) > 1 and x <= a[st[-1]]:
                j = st.pop()
                pre -= a[j] * (j - st[-1])  # 撤销之前加到 pre 中的
            pre += x * (i - st[-1])  # 从 st[-1]+1 到 i 都是 x
            ans = max(ans, pre + suf[i + 1])
            st.append(i)
        return ans

    # leetcode2815 数组中的最大数对和
    def maxSum(self, nums: List[int]) -> int:
        res = -1
        max_val = [-inf] * 10
        for x in nums:
            max_d = max(map(int, str(x)))
            if max_val[max_d] != inf:
                res = max(res, max_val[max_d] + x)
            max_val[max_d] = max(max_val[max_d] ,x)
        return res

    # leetcode2817 限制条件下元素之间的最小绝对差
    def minAbsoluteDifference(self, nums: List[int], x: int) -> int:
        res = inf
        sl = SortedList((-inf, inf))
        for x, y in zip(nums, nums[x:]):
            sl.add(x)
            j = sl.bisect_left(y)
            res = min(res, sl[y] - y, y - sl[j-1])
        return res
    
    # leetcode2733 既不是最小值也不是最大值
    def findNonMinOrMax(self, nums: List[int]) -> int:
        return sorted(nums[:3])[1] if len(nums) > 2 else -1

    # leetcode2784 检查数组是否是好的
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums) - 1
        mp = [0] * n
        for x in nums:
            if x > n: return False
            if x == n and mp[x-1] > 1: return False
            if x < n and mp[x-1] > 0: return False
            mp[x-1] += 1
        return True
    
    # leetcode2319 判断矩阵是否是一个X矩阵
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if i == j or i + j == n - 1:
                    if grid[i][j] == 0: return False
                else:
                    if grid[i][j] != 0: return False
        return True

    # leetcode2923 找到冠军I
    def findChampion(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 1:
            return 0
        n = len(grid[0])
        res = 0
        for i in range(1, m):
            for j in range(0, n):
                if grid[i][j] - grid[res][j] > 0:
                    res = i
                    break
        return res

    # leetcode2924 找到冠军II
    def findChampion2(self, n: int, edges: List[List[int]]) -> int:
        # 找入度为1的节点
        weak = [False] * n
        for _,y in edges:
            weak[y] = True
        res = -1
        for i in range(n):
            if not weak[i]:
                if res != -1:
                    return -1
                res = i
        return res

    # 在闭区间[l, r]中检索第一个不小于t的元素的下标
    def low_bound(self, nums: List[int], t: int) -> int:
        n = len(nums)
        # 闭区间[l, r]
        l = 0
        r = n - 1
        while l <= r: # 这句话的意思是区间不为空
            mid = (r + l) // 2
            if nums[mid] < t:
                # [mid + 1, r]
                l = mid + 1 #必须是mid+1而不是mid,否则就不是闭区间，而变成了左开右闭区间了(l, r]
            else:
                # [l, mid - 1]
                r = mid - 1
        return l
    
    # 在左闭右开区间[l, r)中检索第一个不小于t的元素的下标
    def low_bound2(self, nums: List[int], t: int) -> int:
        n = len(nums)
        # 左闭右开区间[l, r)
        l = 0
        r = n
        while l < r: # 这句话的意思是区间不为空
            mid = (r + l) // 2
            if nums[mid] < t:
                # [mid + 1, r)
                l = mid + 1 #必须是mid+1而不是mid,否则左边就不满足闭区间了
            else:
                # [l, mid)
                r = mid
        return l # return r 也可以，因为此时两者相等
    
    # 在左开区间(l, r)中检索第一个不小于t的元素的下标
    def low_bound3(self, nums: List[int], t: int) -> int:
        n = len(nums)
        # 左闭右开区间(l, r)
        l = -1
        r = n
        while l + 1 < r: # 这句话的意思是区间不为空
            mid = (r + l) // 2
            if nums[mid] < t:
                # (mid, r)
                l = mid #必须是mid+1而不是mid,否则左边就不满足闭区间了
            else:
                # (l, mid)
                r = mid
        return r
    
    # 四种情况：>= 、 >  、 <  、 <=
    # 上面的三种写法都是>=
    # > 可以转换成 >= t + 1 (元素都是整数的话)
    # < 可以转换成 【>= t】 - 1（先找>=的下标然后减1）
    # <= 可以转换成【>t】-1（先找>t的下标然后减一），继而转换成【>=t+1】-1的情形
    # 即后面的三种情况都可以转换成>=的情况

    # leetcode34 在排序数组中查找元素的第一个和最后一个位置
    def searchRange(self, nums: List[int], t: int) -> List[int]:
        # 即找到>=t和<=t的问题
        n = len(nums)
        l = self.low_bound3(nums, t)
        if l >= n or t != nums[l]:
            return [-1, -1]
        r = self.low_bound3(nums, t + 1) - 1
        return [l, r]

    def findPeakElement(self, nums: List[int]) -> int:
        # 开区间(-1, n-1), 相当于闭区间[0, n-2]
        # 使用染色法，mid元素和后一个元素进行比较，如果大于后一个，则mid+1及后面的下标都是蓝色（r=mid）
        # 否则，则mid及前面的下标都是红色（l=mid）
        l = -1
        r = len(nums) - 1
        while l + 1 < r:
            mid = (l + r) // 2
            if nums[mid] > nums[mid+1]:
                r = mid
            else:
                l = mid
        return r

    # leetcode153 寻找旋转排序数组中的最小值
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        # 开区间(0,n-1)，相当于闭区间[1,n-2]
        # 染色法，mid元素和左右两个数比较，
        # 如果nums[l] > nums[r], 说明最小值在mid和r之间
        # 如果nums[r] > nums[mid]，说明最小值在l和mid之间
        
        # 这个判断确定是正常的旋转矩阵（如果是单调递增的不在考虑中） 
        if nums[l] > nums[r]:
            while l + 1 < r:
                mid = (l + r) // 2
                if nums[mid] > nums[l]:
                    l = mid
                elif nums[mid] < nums[r]:
                    r = mid
        return min(nums[l], nums[r])
    
    # leetcode154 寻找旋转排序数组中的最小值II
    def findMin2(self, nums: List[int]) -> int:
        # 和leetcode153的区别是允许有重复元素
        l = 0
        r = len(nums) - 1
        res = nums[l]
        while l + 1 < r:
            mid = (l + r) // 2
            if nums[mid] > nums[l]:
                res = min(res, nums[l])
                l = mid
            elif nums[mid] < nums[r]:
                res = min(res, nums[mid])
                r = mid
            else:
                l += 1
        return min(res, min(nums[l], nums[r]))

    # leetcode2828 判别首字母缩略词
    def isAcronym(self, words: List[str], s: str) -> bool:
        return ''.join([x[0] for x in words]) == s

    # leetcode11 盛最多水的容器
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        res = 0
        while l < r:
            area = min(height[l], height[r]) * (r - l)
            res = max(res, area)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return res
    
    # leetcode1671 得到山形数组的最少删除次数
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        suf = [0] * n
        g = []
        for i in range(n-1, 0, -1):
            x = nums[i]
            j = bisect_left(g, x)
            if j == len(g): # 添加到末尾
                g.append(x)
            else: # 不添加到末尾
                g[j] = x
            suf[i] = j + 1
        
        mx = 0
        g = []
        for i, x in enumerate(nums):
            j = bisect_left(g, x)
            if j == len(g):
                g.append(x)
            else:
                g[j] = x
            pre = j + 1
            if pre >= 2 and suf[i] >= 2:
                mx = max(mx, pre + suf[i] - 1)
        return n - mx

    # leetcode3075 幸福值最大化的选择方案
    def maximumHappinessSum(self, h: List[int], k: int) -> int:
        # 排序，然后最大的值减0（第0个元素），第二大的值要减1（第1个元素），第三大的值要减2（第2个元素）
        # 直到元素小于要减的数
        h.sort(reverse=True)
        res = 0
        n = len(h)
        for i, x in enumerate(h[:k]):
            if x <= i:
                break
            res += x - i
        return res
    
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        s = sum(apple)
        capacity.sort(reverse=True)
        for i, x in enumerate(capacity):
            if s <= 0:
                return i
            s -= x
        return len(capacity)
    
    # leetcode3076 数组中的最短非公共子字符串
    def shortestSubstrings(self, arr: List[str]) -> List[str]:
         def check(i: int, sub: str) -> bool:
            for j, s in enumerate(arr):
                if j != i and sub in s:
                    return False
            return True

        ans = []
        for i, s in enumerate(arr):
            print("s: ", s)
            m = len(s)
            res = ""
            for size in range(1, m + 1):
                for j in range(size, m + 1):
                    t = s[j - size: j]
                    if (not res or t < res) and check(i, t):
                        res = t
                if res: break
            ans.append(res)
        return ans

    def findChampion(self, grid: List[List[int]]) -> int:
        # resolve 20240408
        # 逐行比较，两行相减如果有其中一个差大于0，说明当前行是强的那个，记录强者的行号，然后继续遍历下一行
        n, m = len(grid), len(grid[0])
        ans = 0
        for i in range(1, n):
            for j in range(0, m):
                if grid[i][j] > grid[ans][j]:
                    ans = i
                    break
        return ans

    # leetcode2924 找到冠军II(有向图)
    def findChampionII(self, n: int, edges: List[List[int]]) -> int:
        # resolve 20240408
        weak = [False] * n
        for _,y in edges:
            weak[y] = True
        res = -1
        for i in range(n):
            if not weak[i]:
                if res != -1:
                    return -1
                res = i
        return res





s = 'abcddf'
la = LeetArray()
len = la.countGoodSubstrings(s)
