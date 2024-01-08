

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
    
    # leetcode16 最接近的三数之和
    def threeSumClosest(self, nums: List[int], t: int) -> int:
        nums.sort()
        n = len(nums)
        min_diff = inf
        res = inf
        for i in range(n-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            x = nums[i] + nums[i+1] + nums[i+2]
            if  x > t and x - t < min_diff:
                res = x
                break
            
            x = nums[i] + nums[-2] + nums[-1]
            if x < t and t - x < min_diff:
                min_diff = t - x
                res = x
                continue

            j, k = i + 1, n - 1
            while j < k:
                x = nums[i] + nums[j] + nums[k]
                if x == t:
                    return x
                elif x < t:
                    if t - x < min_diff:
                        min_diff = t - x
                        res = x
                    j += 1
                else:
                    if x - t < min_diff:
                        min_diff = x - t
                        res = x
                    k -= 1
        return res