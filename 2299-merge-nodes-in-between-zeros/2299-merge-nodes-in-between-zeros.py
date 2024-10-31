# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sentinel = ListNode()
        ret = sentinel

        curr = 0
        while head:
            if head.val == 0:
                sentinel.next = ListNode(curr)
                sentinel = sentinel.next
                curr = 0
            else:
                curr += head.val

            head = head.next

        return ret.next.next