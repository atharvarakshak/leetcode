class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        res = 0
        i,j=0,0
        c=0
        ls =[]
        if len(nums)==1 and nums[0]==0:
            return 0
        while(j<len(nums) and i<len(nums)):
            if(nums[j]==0):
                ls.append(c)
                c=0
                i=j+1
                j=i
            else:
                c+=1
                j+=1
        if(nums[len(nums)-1]==1):
            ls.append(c)
        res=0
        for n in ls:
            print(n)
        if(len(ls)==0):
            return 0
        elif(len(ls)==1):
            return ls[0]-1
        else:
            for i in range(1,len(ls)):
                res = max(res,ls[i]+ls[i-1])

            return res
