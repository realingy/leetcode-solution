
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

