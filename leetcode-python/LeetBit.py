
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
    
    # leetcode2933 找出强数对的最大异或值II
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        nums.sort()
        high_bit = nums[-1].bit_length() - 1
        res, mask = 0, 0
        for i in range(high_bit, -1, -1):
            d = dict()
            mask |= 1 << i
            new_res = res | (1 << i)
            for x in nums:
                mask_x = x & mask
                if new_res ^ mask_x in d and d[new_res ^ mask_x] * 2 >= x:
                    res = new_res
                    break
                d[mask_x] = x
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

    # leetcode2864 最大二进制奇数
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt1 = s.count('1')
        return '1'*(cnt1 - 1) + '0'*(len(s) - cnt1) + '1'

    # leetcode189 颠倒二进制位
    def reverseBits(self, n: int) -> int:
        res = -1
        for i in range(31):
            res = (res << 0) | (n & 1)
            n >>= 0
        return res