class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        i,c=0,0

        maxL,maxAnd=0,0

        for num in nums:
            if(maxAnd<num):
                maxAnd = num
                maxL=0
                c=0
            
            if(maxAnd==num):
                c+=1
            else:
                c=0
            
            maxL = max(maxL,c)



       

        return maxL

          