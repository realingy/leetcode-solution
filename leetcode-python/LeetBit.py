
class LeetBit:
    # leetcode2520 统计能整除数字的位数
    def countDigits(self, num: int) -> int:
        x = num
        res = 0
        while x:
            if 0 == num % (x % 10):
                res += 1
            x //= 10
        return res
