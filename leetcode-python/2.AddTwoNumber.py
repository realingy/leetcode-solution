#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author:ingy time:2019/9/22

class ListNode:
    """
    定义节点类
    data:数据
    _next:下一个数据
    """
    def __init__(self, v):
        self.val = v
        self.next = None

    def __repr__(self):
        """
        用来定义Node的字节输出
        """
        return str(self.val)

class List:
    def __init__(self):
        self.header = None
        self.length = 0

    def append(self, val):
        item = ListNode(val)

        if not self.header:
            self.header = item
            self.length += 1
        else:
            node = self.header
            while node.next:
                node = node.next
            node.next = item
            self.length += 1

    def show(self):
        node = self.header
        while node:
            if node.next:
                print(node.val, end="->")
            else:
                print(node.val)
            node = node.next

class Solution():
    def addTwoNumber(self, l1, l2):
        """
        :type l1: List
        :type l2: List
        :rtype: List
        """
        res = ListNode(-1)
        cur = res
        carry = 0
        n1 = l1.header
        n2 = l2.header
        while (n1 or n2):
            v1 = n1.val
            v2 = n2.val
            sum = v1 + v2 + carry
            carry = int(sum / 10)
            cur.next = ListNode(int(sum % 10))
            cur = cur.next
            if (n1):
                n1 = n1.next
            if (n2):
                n2 = n2.next

        if carry:
            cur.next = ListNode(1)

        list = List()
        node = res.next
        while(node):
            list.append(node)
            node = node.next
        return list

    def addTwoNumber2(self, l1, l2):
        """
        :type l1: List
        :type l2: List
        :rtype: List
        """
        n = l1.header
        i = 1
        num1 = 0
        while n:
            num1 = num1 + n.val * i
            i = i * 10
            n = n.next

        m = l2.header
        j = 1
        num2 = 0
        while m:
            num2 = num2 + m.val * j
            j = j * 10
            m = m.next

        num = str(num1 + num2)
        num = num[::-1]
        result = List()
        for s in num:
            result.append(int(s))
        return result


if __name__ == "__main__":
    # S = Solution()
    # l1 = ListNode(2)
    # l1.append(4)
    # l1.next.append(3)
    #
    # l2 = ListNode(5)
    # l2.append(6)
    # l2.next.append(4)
    #
    # list = S.addTwoNumber2(l1, l2)
    # print(list)

    S = Solution()
    l1 = List()
    l1.append(2)
    l1.append(4)
    l1.append(3)

    l2 = List()
    l2.append(5)
    l2.append(6)
    l2.append(4)

    list = S.addTwoNumber(l1, l2)
    print("l1: ", end=""), l1.show()
    print("l2: ", end=""), l2.show()
    print("result: ", end=""), list.show()
