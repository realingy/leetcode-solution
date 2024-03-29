#ifndef __LEET_SORT_H__
#define __LEET_SORT_H__

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace myleet {

class LeetSort {
 public:
  LeetSort() {}
  ~LeetSort() {}

 public:
  // leetcode169 多数元素
  static int majorityElement(std::vector<int>& nums);
  // leetcode217 存在重复元素
  static bool containsDuplicate(std::vector<int>& nums);
  // leetcode219 存在靠近的重复元素
  static bool containsNearbyDuplicate(std::vector<int>& nums, int k);
  // leetcode242 有效异位词
  static bool isAnagram(std::string s, std::string t);
  // leetcode268 丢失的数字
  static int missingNumber(std::vector<int>& nums);
  // leetcode349 交集
  static std::vector<int> intersection(std::vector<int>& nums1,
                                       std::vector<int>& nums2);
  // leetcode350 交集2
  static std::vector<int> intersection2(std::vector<int>& nums1,
                                        std::vector<int>& nums2);
  // leetcode389 找不同
  static char findTheDifference(std::string s, std::string t);
  // leetcode414 第三大数
  static int thirdMax(std::vector<int>& nums);
  // leetcode455 分饼干
  static int findContentChildren(std::vector<int>& g, std::vector<int>& s);
  // leetcode506 相对名次
  static std::vector<std::string> findRelativeRanks(std::vector<int>& score);
  // leetcode561 拆分数组
  static int arrayPairSum(std::vector<int>& nums);
  // leetcode594 最长和谐子序列
  static int findLHS(std::vector<int>& nums);
  // leetcode628 最大三数乘积
  static int maximumProduct(std::vector<int>& nums);
  // leetcode645 丢失的数字
  static std::vector<int> findErrorNums(std::vector<int>& nums);
  // leetcode747 至少是其他数字（次大值）两倍的最大数
  static int dominantIndex(std::vector<int>& nums);
  // leetcode888 公平的糖果交换
  static std::vector<int> fairCandySwap(std::vector<int>& aliceSizes,
                                        std::vector<int>& bobSizes);
  // leetcode905 按奇偶数重新排列
  static std::vector<int> sortArrayByParity(std::vector<int>& nums);
  // leetcode922 按奇偶数重新排列2
  static std::vector<int> sortArrayByParityII(std::vector<int>& nums);
  // leetcode976 最大周长
  static int largestPerimeter(std::vector<int>& nums);
  // leetcode977 有序数组的平方
  static std::vector<int> sortedSquares(std::vector<int>& nums);
  // leetcode1005 K次取反后最大化的数组和
  static int largestSumAfterKNegations(std::vector<int>& nums, int k);
  // leetcode1051 高度检查器
  static int heightChecker(std::vector<int>& heights);
  // leetcode1122 数组的相对排序
  static std::vector<int> LeetSort::relativeSortArray(std::vector<int>& arr1,
                                                      std::vector<int>& arr2);
  // leetcode1200 最小绝对差
  static std::vector<std::vector<int>> minimumAbsDifference(
      std::vector<int>& arr);
  // leetcode1331 数组序号转换
  static std::vector<int> arrayRankTransform(std::vector<int>& arr);
  // leetcode1337 矩阵中战斗力最弱的 K 行
  static std::vector<int> LeetSort::kWeakestRows(
      std::vector<std::vector<int>>& mat, int k);
  // leetcode56 合并区间
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);
};

}  // namespace myleet

#endif