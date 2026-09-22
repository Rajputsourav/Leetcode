class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        # Convert string to list since strings are immutable in Python
        chars = list(s)
        
        # Step through the string in chunks of 2k
        for i in range(0, len(chars), 2 * k):
            # Reverse the first k characters in the current 2k block
            chars[i:i + k] = reversed(chars[i:i + k])
            
        return "".join(chars)     