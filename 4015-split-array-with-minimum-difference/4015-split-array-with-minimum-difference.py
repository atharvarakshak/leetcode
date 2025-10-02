class Solution:
    def splitArray(self, arr: List[int]) -> int:
        ok = True
        cnt=0
        n = len(arr)
        l,r=0,n-1
        ls,rs=0,0
        while(l<n-1 and arr[l]<arr[l+1]):
            ls+=arr[l]
            l+=1

        while(r>0 and arr[r-1]>arr[r]):
            rs+=arr[r]
            r-=1

        if(l==r):
            return min(abs(ls+arr[l]-rs),abs(ls -rs-arr[r]))

        elif(r-l==1 and arr[l]==arr[r]):
            return abs(ls-rs)


        else:
            return -1

        

        


