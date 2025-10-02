class Solution:
    def decimalRepresentation(self, n: int) -> List[int]:
        res=[]
        p=1
        while(n>0):
            x = n%10
            x = x*p
            p=p*10
            n//=10
            if(x!=0):
                res.append(x)

        res.sort(reverse=True)
        return res
