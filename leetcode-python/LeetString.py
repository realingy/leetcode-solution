
class LeetString:
    # leetcode2255 统计是给定字符串前缀的字符串数目
    def countPrefixes(self, words: List[str], s: str) -> int:
        res = 0
        for word in words:
            res += (0 == s.find(word))
        return res

    # leetcode1374 生成每种字符都是奇数个的字符串
    def generateTheString(self, n: int) -> str:
        return 'a' + 'b' * (n-1) if 0 == n%2 else 'a' * n

    # leetcode2490 回环句
    def isCircularSentence(self, s: str) -> bool:
        return s[0] == s[-1] and all(c != ' ' or s[i-1] == s[i+1] for i, c in enumerate(s))

    # leetcode1408 数组中的字符串匹配
    def stringMatching(self, words: List[str]) -> List[str]:
        word_str = ' '.join(words)
        res = []
        for s in words:
            if word_str.count(s) > 1:
                res.append(s)
        return res

    # leetcode1528 重新排列字符串
    def restoreString(self, s: str, indices: List[int]) -> str:
        n = len(s)
        res = ["" for i in range(len(s))]
        for i in range(n):
            res[indices[i]] = s[i]
        return "".join(res)
    
    # leetcode1598 文件夹操作日志搜集器
    def minOperations(self, logs: List[str]) -> int:
        depth = 0
        for log in logs:
            if "../" == log: 
                depth = max(depth - 1, 0)
            elif "./" != log:
                depth += 1
        return depth

    # leetcode1629 按键持续时间最长的键
    def slowestKey(self, t: List[int], k: str) -> str:
        max = -inf
        idx = -1
        for i in range(len(t) - 1, -1, -1):
            if i > 0: t[i] -= t[i-1]
            if t[i] > max:
                max = t[i]
                idx = i
            elif t[i] == max and k[i] > k[idx]:
                idx = i
        return k[idx]

    # leetcode1662 检查两个字符串数组是否相等
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return ''.join(word1) == ''.join(word2)
    
    # leetcode1684 统计一致字符串的数目
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        res = 0
        for word in words:
            match = True
            for x in word:
                if x not in allowed:
                    match = False
                    break
            if match == True:
                res += 1
        return res 

    # leetcode1773 统计匹配检索规则的物品数量
    def countMatches(self, items: List[List[str]], k: str, v: str) -> int:
        map = {'type': 0, 'color': 1, 'name': 2}
        return sum(item[map[k]] == v for item in items)

    # leetcode1816 截断句子
    def truncateSentence(self, s: str, k: int) -> str:
        return ' '.join(s.split(' ')[:k]) # 先把句子slip成数组，再把前k个str通过空格连接就好了

    # leetcode1961 检查字符串是否为数组前缀
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        # 前若干个str拼接，能拼接成s就满足条件，直接返回
        return any(''.join(words[:i+1]) == s for i in range(len(words)))

    # leetcode2011 执行操作后的变量值
    def finalValueAfterOperations(self, o: List[str]) -> int:
        map = {'X++': 1, '++X': 1, 'X--': -1, '--X': -1}
        return sum(map[x] for x in o)

    # leetcode2053 数组中第 K 个独一无二的字符串
    def kthDistinct(self, arr: List[str], k: int) -> str:
        a = [v for v, c in Counter(arr).items() if c == 1]
        return "" if k > len(a) else a[k-1]

    # leetcode2085 统计出现过一次的公共字符串
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        # return len({w for w, c in Counter(words1).items() if c == 1} & {w for w, c in Counter(words2).items() if c == 1})
        freq1 = Counter(words1)   # words1 中字符串的出现次数
        freq2 = Counter(words2)   # words2 中字符串的出现次数
        res = 0   # 出现过一次的公共字符串个数
        for word1 in freq1.keys():
            # 遍历 words1 出现的字符并判断是否满足要求
            if freq1[word1] == 1 and freq2[word1] == 1:
                res += 1
        return res

    # leetcode2734 执行子串操作后的字典序最小字符串
    def smallestString(self, s: str) -> str:
        t = list(s)
        for i, c in enumerate(t):
            if c != 'a':
                for j in range(i, len(t)):
                    if t[j] == 'a':break
                    t[j] = chr(ord(t[j]) - 1)
                return ''.join(t)
        t[-1] = 'z'
        return ''.join(t)
    
    # leetcode2869 收集元素的最少操作次数
    def minOperations(self, nums: List[int], k: int) -> int:
        # resolve 20231204
        """
        st = set()
        n = len(nums)
        for i in range(n-1, -1, -1):
            if nums[i] <= k:
                st.add(nums[i])
                if len(st) == k:
                    return n - i
        """
        # ans 20231204
        # 掩码 u，该掩码的二进制表示中，从最低位开始，连续 k 个比特都是1，其余比特都是0
        u = (2 << k) - 2  # 1~k
        s, n = 0, len(nums)
        for i in range(n - 1, -1, -1):
            # 将当前元素的比特位置1
            s |= 1 << nums[i]
            # 检查是否构成了一个长度为 k 的连续子序列，即 s 的低 k 个比特是否都为1
            if (s & u) == u:
                return n - i

    # leetcode2108 找出数组中的第一个回文字符串
    def firstPalindrome(self, words: List[str]) -> str:
        return next((x for x in words if x == x[::-1] ), "")

    # leetcode2114 句子中的最多单词数
    def mostWordsFound(self, s: List[str]) -> int:
        res = 0
        for x in s:
            res = max(res, x.count(' ') + 1)
        return res

    # leetcode2185 统计包含给定前缀的字符串
    def prefixCount(self, words: List[str], pref: str) -> int:
        # resolve 20231205
        # n = len(pref)
        # return sum((pref == x[:n] for x in words))
        # ans 20231205
        return sum(w.startswith(pref) for w in words)

    # leetcode2452 距离字典两次编辑以内的单词
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
      res = []
      for q in queries:
        for d in dictionary:
          if sum(x != y for x, y in zip(q, d)) <= 2:
            res.append(q)
            break
      return res