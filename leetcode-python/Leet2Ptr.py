

class LeetTwoPtr:
    # leetcode151 反转字符串中的单词
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))

    # leetcode167 两数之和II-输入有序数组
    def twoSum(self, nums: List[int], t: int) -> List[int]:
        i = 0
        j = len(nums) - 1
        while i < j:
            x = nums[i] + nums[j]
            if x < t:
                i += 1
            elif x > t:
                j -= 1
            else:
                return [i+1, j+1]
    
    # leetcode15 三数之和
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)
        for i in range(n-2):
            if nums[i] + nums[i+1] + nums[i+2] > 0: continue
            if nums[i] + nums[n-2] + nums[n-1] < 0: continue
            x = nums[i]
            if i > 0 and nums[i-1] == x:
                continue
            j = i + 1
            k = n - 1
            while j < k:
                cur = x + nums[j] + nums[k]
                if cur == 0:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                elif cur < 0:
                    j += 1
                else:
                    k -= 1
        return res