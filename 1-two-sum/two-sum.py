class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        n = len(nums)
        for i in range(0, n):
            remaining = target - nums[i]
            if remaining in hash_map:
                return [hash_map[remaining],i]
            hash_map[nums[i]] = i    
        