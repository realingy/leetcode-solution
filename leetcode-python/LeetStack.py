
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

    # leetcode2866 美丽塔II
    def maximumSumOfHeights(self, a: List[int]) -> int:
        # 单调栈
        # 1、相同的数，只需要维护最左边的元素的下标
        # 2、用单调栈维护
        n = len(a)
        suf = [0] * (n + 1)
        st = [n]
        s = 0
        for i in range(n - 1, -1, -1):
            x = a[i]
            while len(st) > 1 and x <= a[st[-1]]:
                j = st.pop()
                s -= a[j] * (st[-1] - j)  # 撤销之前加到 s 中的
            s += x * (st[-1] - i)  # 从 i 到 st[-1]-1 都是 x
            suf[i] = s
            st.append(i)

        ans = s
        st = [-1]
        pre = 0
        for i, x in enumerate(a):
            while len(st) > 1 and x <= a[st[-1]]:
                j = st.pop()
                pre -= a[j] * (j - st[-1])  # 撤销之前加到 pre 中的
            pre += x * (i - st[-1])  # 从 st[-1]+1 到 i 都是 x
            ans = max(ans, pre + suf[i + 1])
            st.append(i)
        return ans

    # ALG0601 <==> leetcode946
    # leetcode946 验证栈序列
    def validateStackSequences(self, s: List[int], t: List[int]) -> bool:
        n = len(s)
        st = []
        i, j = 0, 0
        while j < n:
            if len(st) > 0 and st[-1] == t[j]:
                st.pop()
                j += 1
            elif i < n:
                st.append(s[i])
                i += 1
            else:
                return False

        return True if 0 == len(st) else False
    
    # leetcode316 去除重复字母
    # leetcode1081 不同字符的最小子序列
    # 1 统计每个字母的出现次数，记到一个哈希表或者数组left中
    # 2 遍历s，先把 left[s[i]] 减一
    # 3 如果 s[i] 在 ans 中，直接 continue。为了快速判断 s[i] 是否在 ans 中，可以创建一个哈希表或者布尔数组 inAns
    # 4 如果 s[i] 不在 ans 中，那么判断 s[i] 是否小于 ans 的最后一个字母（记作 x），如果 s[i]<x 且 left[x]>0，那么可以把 x 从 ans 中去掉，同时标记 inAns[x]=false
    # 5 反复执行第 4 步，直到 ans 为空，或者 s[i]>x，或者 left[x]=0
    # 6 把 s[i] 加到 ans 末尾，同时标记 inAns[s[i]]=true。然后继续遍历 s 的下一个字母。
    # 7 遍历完 s 后，返回 ans
    def removeDuplicateLetters(self, s: str) -> str:
        left = Counter(s)
        res = []
        in_res = set()
        for c in s:
            left[c] -= 1
            if c in in_res:
                continue
            while res and c < res[-1] and left[res[-1]]:
                in_res.remove(res.pop())
            res.append(c)
            in_res.add(c)
        return ''.join(res)

    # leetcode331 验证二叉树的前序序列化
    def isValidSerialization(self, a: str) -> bool:
        st = []
        for n in a.split(','):
            st.append(n)
            while len(st) >= 3 and st[-1] == st[-2] == '#' and st[-3] != '#':
                st.pop(), st.pop(), st.pop()
                st.append('#')
        return len(st) == 1 and st.pop() == '#'

    # leetcode20 合理的括号
    def isValid(self, s: str) -> bool:
        st = []
        for x in s:
            if '(' == x:
                st.append(')')
            elif '[' == x:
                st.append(']')
            elif '{' == x:
                st.append('}')
            elif len(st) == 0:
                return False
            elif st[-1] != x:
                return False
            else:
                st.pop()
        return len(st) == 0