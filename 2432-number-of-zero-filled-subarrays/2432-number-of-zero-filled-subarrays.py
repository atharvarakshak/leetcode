class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        c=0
        i,j=0,0

        while(j<n):
            if(nums[j]==0):
                i+=1
                c+=i

            else:
                i=0
            j+=1
                
        return c
        


