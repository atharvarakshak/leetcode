from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res=0
        i,j=0,0
        cur=0
        n = len(nums)
        mp = defaultdict(int) 
        mp[0] = 1

        while(j<n):
            cur += nums[j]
            if((cur-k) in mp.keys()):
                res+=mp[cur-k]
            mp[cur]+=1
            j+=1
       

        return res