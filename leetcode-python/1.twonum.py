#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author:ingy time:2019/9/21

class Solution:
    def twoSum(self, nums, target):
        i = 0
        while i < len(nums):
            if i == len(nums) - 1:
                return "No solution here!"
            r = target - nums[i]
            # Can't use a num twice
            num_follow = nums[i + 1:]
            if r in num_follow:
                return [i, num_follow.index(r) + i + 1]
            i = i + 1

if __name__ == "__main__":
    # print("hello python")
    s = Solution()
    nums = [2, 7, 8, 9]
    indexs = s.twoSum(nums, 9)
    print(indexs)

