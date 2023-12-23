
class LeetHeap:
    # leetcode1962 移除石子使总数最小
    def minStoneSum(self, piles: List[int], k: int) -> int:
        for i in range(len(piles)):
            piles[i] *= -1
        heapify(piles) # 原地堆化
        while k and piles[0]:
            # 替换最小值（即原数组的最大值），且负数的向下取整等于整数向上取整
            heapreplace(piles, piles[0] // 2)
            k -= 1
        return -sum(piles) 

