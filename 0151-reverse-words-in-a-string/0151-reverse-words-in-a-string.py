class Solution:
    def reverseWords(self, s: str) -> str:
        new_s = s.split()
        new_s = new_s[::-1]
        res=""
        for c in new_s:
            res+=c
            res+=' '

        return res[:len(res)-1]
