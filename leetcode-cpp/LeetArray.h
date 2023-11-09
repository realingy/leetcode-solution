#ifndef __LEET_ARRAY_H__
#define __LEET_ARRAY_H__

#include "data.h"

namespace myleet {

class LeetArray {
 public:
  LeetArray() {}
  ~LeetArray() {}

 public:
  // leetcode1534 统计好三元组
  static int countGoodTriplets(std::vector<int>& arr, int a, int b, int c);
  // leetcode1566 重复至少 K 次且长度为 M 的模式
  static bool containsPattern(std::vector<int>& arr, int m, int k);
  // leetcode1925 统计平方和三元组的数目
  static int countTriples(int n);
  // leetcode1995 统计特殊四元组
  static int countQuadruplets(std::vector<int>& nums);
  // leetcode2094 找出3位偶数
  static std::vector<int> findEvenNumbers(std::vector<int>& digits);
  // leetcode2259 移除指定数字得到的最大结果
  static std::string removeDigit(std::string number, char digit);
  // leetcode2309 兼具大小写的最好英文字母
  static std::string greatestLetter(std::string s);
  // leetcode2367 算术三元组的数目
  static int arithmeticTriplets(std::vector<int>& nums, int diff);
  // leetcode2427 公因子的数目
  static int commonFactors(int a, int b);
  // leetcode2437 有效时间的数目
  static int countTime(std::string time);
  // leetcode2605 从两个数字数组里生成最小数字
  static int minNumber(std::vector<int>& nums1, std::vector<int>& nums2);
  // leetcode2765 最长交替子序列
  static int alternatingSubarray(std::vector<int>& nums);
  // leetcode2798 满足目标工作时长的员工数目
  static int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target);
  // leetcode2843 统计对称整数的数目
  static int countSymmetricIntegers(int low, int high);
  // leetcode845 数组中的最长山脉
  static int longestMountain(std::vector<int>& arr);
  // leetcode949 给定数字能组成的最大时间
  static std::string largestTimeFromDigits(std::vector<int>& arr);
  // leetcode1291 顺次数
  static std::vector<int> sequentialDigits(int low, int high);
  // leetcode1620 网络信号最好的坐标
  static std::vector<int> bestCoordinate(std::vector<std::vector<int>>& towers,
                                         int radius);
  // leetcode167 两数之和II-输入有序数组
  static std::vector<int> twoSum(std::vector<int>& numbers, int target);
  // leetcode15 三数之和
  static std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
  // leetcode11 盛最多水的容器
  static int maxArea(std::vector<int>& height);
  // leetcode42 接雨水
  static int trap(std::vector<int>& height);
  // leetcode49 字母异位词分组
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs);
};

}  // namespace myleet

#endif