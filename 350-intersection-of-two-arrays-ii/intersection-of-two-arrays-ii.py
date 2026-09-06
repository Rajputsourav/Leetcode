class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        c = Counter(nums1)
        res = []
        for i in nums2:
            if c[i] > 0:
                res.append(i)
                c[i] =c[i]- 1
        return res                

        