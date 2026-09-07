class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        res = []
        n = len(nums)
        for i in range(0, n):
            res.append(nums[i] * nums[i])

        res.sort()
        return res