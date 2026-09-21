# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        min_diff = float('inf')
        prev_val = -float('inf')
        
        def inorder(node):
            nonlocal min_diff, prev_val
            if not node:
                return
            
            # Traverse left subtree
            inorder(node.left)
            
            # Process current node
            min_diff = min(min_diff, node.val - prev_val)
            prev_val = node.val
            
            # Traverse right subtree
            inorder(node.right)
            
        inorder(root)
        return min_diff     