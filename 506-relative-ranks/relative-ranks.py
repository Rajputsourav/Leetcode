class Solution:
    def findRelativeRanks(self, score: list[int]) -> list[str]:
        n = len(score)
        ans = [""] * n
        
        sorted_indices = sorted(range(n), key=lambda i: score[i], reverse=True)
        
        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        
        for rank, idx in enumerate(sorted_indices):
            if rank < 3:
                ans[idx] = medals[rank]
            else:
                ans[idx] = str(rank + 1)
                
        return ans