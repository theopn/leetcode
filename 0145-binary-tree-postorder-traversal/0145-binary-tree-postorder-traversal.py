# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # LRN
        ls = []
        def postorder(root, ls):
            if not root:
                return
                
            postorder(root.left, ls)
            postorder(root.right, ls)
            ls.append(root.val)

        postorder(root, ls)
        return ls