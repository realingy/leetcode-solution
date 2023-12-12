
class LeetStack:
    # leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==> leetcode1019
    # leetcode1475 商品折扣后的最终价格
    def finalPrices(self, prices: List[int]) -> List[int]:
        res = [x for x in prices]
        st = []
        n = len(prices)
        for i in range(n-1, -1, -1):
            x = prices[i]
            while len(st) > 0 and x < prices[st[-1]]:
                st.pop()
            if len(st) > 0:
                res[i] -= prices[st[-1]]
            st.append(i)
        return res    

    # leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==> leetcode1019
    # leetcode739 每日温度
    def dailyTemperatures(self, temp: List[int]) -> List[int]:
        st = []
        n = len(temp)
        res = [int] * n
        for i in range(n-1, -1, -1):
            x = temp[i]
            while st and x >= temp[st[-1]]:
                st.pop()
            if st:
                res[i] = st[-1] - i
            else:
                res[i] = 0
            st.append(i)
        return res

    # leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==> leetcode1019
    # leetcode496 下一个更大元素I
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums2)
        st = []
        dct = defaultdict(int)
        for i in range(n-1, -1, -1):
            x = nums2[i]
            while st and x > st[-1]:
                st.pop()
            if st:
                dct[x] = st[-1]
            else:
                dct[x] = -1
            st.append(x)
        res = []
        for x in nums1:
            res.append(dct[x])
        return res
    
    # leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==> leetcode1019
    # leetcode503 下一个更大元素II
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        nums *= 2
        n = len(nums)
        st = []
        arr = [int] * n
        for i in range(n - 1, -1, -1):
            x = nums[i]
            while st and x >= st[-1]:
                st.pop()
            if st:
                arr[i] = st[-1]
            else:
                arr[i] = -1
            st.append(x)
        return arr[:n//2]

    # leetcode739 <==> leetcode1475 <==> leetcode496 <==> leetcode503 <==> leetcode1019
    # leetcode1019 链表中的下一个更大节点
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        nums = []
        while head is not None:
            nums.append(head.val)
            head = head.next
        st = []
        n = len(nums)
        res = [0] * n
        for i in range(n-1, -1, -1):
            x = nums[i]
            while st and x >= st[-1]:
                st.pop()
            if st:
                res[i] = st[-1]
            st.append(x)
        return res