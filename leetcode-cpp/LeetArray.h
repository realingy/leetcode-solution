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
  static std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs);
  // leetcode57 插入区间
  static std::vector<std::vector<int>> insert(
      std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval);
  // leetcode58 最后一个单词的长度
  static int lengthOfLastWord(std::string s);
  // leetcode209 长度最小的子数组
  int minSubArrayLen(int target, std::vector<int>& nums);
  // leetcode713 乘积小于K的子数组
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k);
  // leetcode3 无重复字符的最长子串
  int lengthOfLongestSubstring(std::string s);
  // leetcode74 搜索二维矩阵
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
  // leetcode75 颜色分类
  void sortColors(std::vector<int>& nums);
  // leetcode34 在排序数组中查找元素的第一个和最后一个位置
  std::vector<int> searchRange(std::vector<int>& nums, int target);
  // leetcode162 寻找峰值
  int findPeakElement(std::vector<int>& nums);
  // leetcode153 寻找旋转数组的最小值
  int findMin(std::vector<int>& nums);
  // leetcode33 搜索旋转排序数组
  int search(std::vector<int>& nums, int target);
  // leetcode35 搜索插入位置
  int searchInsert(std::vector<int>& nums, int target);
  // leetcode278 第一个错误的版本
  int firstBadVersion(int n);
  // leetcode202 快乐数
  bool isHappy(int n);
  // leetcode2937. 使三个字符串相等
  int findMinimumOperations(std::string s1, std::string s2, std::string s3);
  // leetcode2938 区分黑球与白球
  long long minimumSteps(std::string s);
  // leetcode2939 最大异或乘积
  int maximumXorProduct(long long a, long long b, int n);
  // leetcode2760 最长奇偶子数组
  int longestAlternatingSubarray(std::vector<int>& nums, int threshold);
  // leetcode2932 找出强数对的最大异或值 I
  static int maximumStrongPairXor(std::vector<int>& nums);
  // leetcode2935 找出强数对的最大异或值II
  static int maximumStrongPairXor2(std::vector<int>& nums);
  // leetcode2934 最大化数组末位元素的最少操作次数
  int minOperations(std::vector<int>& nums1, std::vector<int>& nums2);
  // leetcode2928 给小朋友们分糖果 I
  static int distributeCandies(int n, int limit);
  // leetcode2929 给小朋友们分糖果II
  static long long distributeCandies2(int n, int limit);
  // leetcode2927 给小朋友们分糖果III
  static long long distributeCandies3(int n, int limit);
  // leetcode2930 重新排列后包含指定子字符串的字符串数目
  static int stringCount(int n);
  // leetcode2262 字符串的总引力
  static long long appealSum(std::string s);
  // leetcode828. 统计子串中的唯一字符
  static int uniqueLetterString(std::string s);
  // leetcode2522 将字符串分割成值不超过 K 的子字符串
  static int minimumPartition(std::string s, int k);
  // leetcode2521 数组乘积中的不同质因数数目
  static int distinctPrimeFactors(std::vector<int>& nums);
  // leetcode896 单调数列
  static bool isMonotonic(std::vector<int>& nums);
  // leetcode643 子数组最大平均数I
  double findMaxAverage(std::vector<int>& nums, int k);
  // leetcode1763 最长的美好子字符串
  std::string longestNiceSubstring(std::string s);
  // leetcode1876 长度为三且各字符不同的子字符串
  int countGoodSubstrings(std::string s);
  // leetcode485 最大连续1的个数
  int findMaxConsecutiveOnes(std::vector<int>& nums);
  // leetcode2515 到目标字符串的最短距离
  static int closetTarget(std::vector<std::string>& words, std::string target,
                          int startIndex);
  // leetcode2516 每种字符至少取K个
  int takeCharacters(std::string s, int k);
  // leetcode2517 礼盒的最大甜蜜度
  int maximumTastiness(std::vector<int>& price, int k);
  // leetcode2518 好分区的数目
  int countPartitions(std::vector<int>& nums, int k);
};

}  // namespace myleet

#endif