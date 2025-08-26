class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        mp ={}

        for c in s:
            mp[c] = mp.get(c,0)+1

        st = ""
        for c in t:
            if(mp.get(c,0)>0):
                mp[c]-=1
            else:
                st+=c

        return st