class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0
        for i in range(0 , len(nums)):
            if(nums[i] != 0 ):
                temp = nums[i]
                nums[i] = 0
                nums[j] = temp
                j = j+1
        