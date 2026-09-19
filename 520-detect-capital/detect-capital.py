class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cap_count = sum(1 for char in word if char.isupper())
        
        return cap_count == len(word) or cap_count == 0 or (cap_count == 1 and word[0].isupper())