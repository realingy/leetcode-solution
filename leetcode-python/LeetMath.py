
class LeetMath:
    def isPerfectSquare(self, num: int) -> bool:
        """
        # 暴力
        i = 1
        while i * i < num:
            i += 1
        return i * i == num
        """
        """
        # 二分法
        l, r = 1, num
        while l < r:
            mid = (l + r) // 2
            if mid * mid < num:
                l = mid + 1
            else:
                r = mid
        return l * l == num
        """
        # 数学，N^2 = 1 + 3 + 5 + ... + (2 * N - 1)
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0







