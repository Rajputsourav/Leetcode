class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n = nums.sort()
        l = len(nums)
        for i in range(1, l):
            if(nums[i] == nums[i-1]):
                return True

        return False


        