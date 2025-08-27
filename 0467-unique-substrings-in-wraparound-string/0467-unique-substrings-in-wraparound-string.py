class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:
        le = defaultdict(lambda:0)
        l=1
        le[s[0]]=1

        S = "abcdefghijklmnopqrstuvwxyza"
        for idx in range(1,len(s)):
            if(s[idx-1:idx+1] in S ):
                l +=1
            else:
                l = 1
            le[s[idx]] = max(le[s[idx]],l)

        return sum(le.values())