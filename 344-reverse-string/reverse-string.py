class Solution:
    def reverseString(self, s: List[str]) -> None:
        l=0
        temp=''
        n = len(s)
        r=n-1
        while(l < r ):
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1
        

        