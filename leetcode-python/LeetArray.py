
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

s = 'abcddf'
la = LeetArray()
len = la.countGoodSubstrings(s)


    
