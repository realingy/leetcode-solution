
class LeetList:
    # leetcode2487 从链表中移除节点
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        res = self.removeNodes(head.next)
        if res is None:
            return head
        if res.val > head.val:
            return res
        head.next = res
        return head
    
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return new_head
    
    def addTwo(self, l1: Optional[ListNode], l2: Optional[ListNode], carry=0) -> Optional[ListNode]:
        if l1 is None and l2 is None:
            return ListNode(carry) if carry else None  # 如果进位了，就额外创建一个节点
        if l1 is None:  # 如果 l1 是空的，那么此时 l2 一定不是空节点
            l1, l2 = l2, l1  # 交换 l1 与 l2，保证 l1 非空，从而简化代码
        carry += l1.val + (l2.val if l2 else 0)  # 节点值和进位加在一起
        l1.val = carry % 10  # 每个节点保存一个数位
        l1.next = self.addTwo(l1.next, l2.next if l2 else None, carry // 10)  # 进位
        return l1

    # leetcode445 两数相加II
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = self.reverseList(l1)
        l2 = self.reverseList(l2)
        l3 = self.addTwo(l1, l2)
        return self.reverseList(l3)

    # leetcode2816 翻倍以链表形式表示的数字
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 下个节点的值大于4表示需要进位，将当前节点的值加1即可，首先当head的值大于4，则需要在head前加一个空节点
        if head.val > 4:
            head = ListNode(0, head)
        cur = head
        while cur:
            cur.val = cur.val * 2 % 10
            if cur.next and cur.next.val > 4:
                cur.val += 1
            cur = cur.next
        return head

        # 另一种解法是参考445的办法，自己加自己
        l = self.reverseList(head)
        l3 = self.addTwo(l, l)
        return self.reverseList(l3)







