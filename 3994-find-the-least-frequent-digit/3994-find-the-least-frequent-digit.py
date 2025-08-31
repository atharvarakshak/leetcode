class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        mp={}

        while(n>0):
            mp[n%10] = mp.get(n%10,0)+1

            n//=10

        
        return min(mp, key= lambda k: (mp[k],k))

        