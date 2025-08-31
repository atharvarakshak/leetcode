class Solution:
    def score(self, cards: List[str], x: str) -> int:
        n,m,k=0,0,0
        a,b={},{}

        for i in range(len(cards)):
            if(cards[i][0]==cards[i][1] and cards[i][0]==x):
                k+=1
            elif(cards[i][0]==x):
                a[cards[i]] = a.get(cards[i],0)+1
                n+=1
            elif(cards[i][1]==x): 
                b[cards[i]] = b.get(cards[i],0)+1
                m+=1

        a_max,b_max=0,0

        for v in a.values():
            a_max = max(a_max,v)

        
        for v in b.values():
            b_max = max(b_max,v)

        pair1,pair2=0,0

        pair1 = min(n//2,n - a_max)
   

        unpair = n - 2*pair1

        pair2 = min(m//2,m-b_max)
        unpair += m - 2*pair2

        ans=pair1+pair2+min(k,unpair)

        if(k>unpair):
            ans+=min((k-unpair)//2,pair1+pair2)

        print(pair1,pair2,k,unpair)

        return ans