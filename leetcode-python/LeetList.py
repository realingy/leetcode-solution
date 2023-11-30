
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