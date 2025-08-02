class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:

        mp = Counter()
    
        m=float("inf")
        n = len(basket1)

        for b1 in basket1:
            mp[b1]+=1
            m = min(m,b1)
        for b2 in basket2:
            mp[b2]-=1
            m= min(m,b2)

        merge=[]

        for k,c in mp.items():
            if(c%2!=0):
                return -1
            
            merge.extend([k]*(abs(c)//2))

        merge.sort()

        return sum(min(2*m,x) for x in merge[: len(merge)//2])


        


        


        for x in mp.values():
            if(x%2!=0):
                return -1

        return 0