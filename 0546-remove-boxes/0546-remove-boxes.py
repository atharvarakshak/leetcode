class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        count=0
        # @lru_cache(None)
        memo={}
        def dp(l,r,count=0):
            if(l>r):
                return count
            if( l+1<=r and boxes[l]==boxes[l+1]):
                l+=1
                count+=1
            if (l, r, count) in memo:
                return memo[(l, r, count)]
            
            ans = (count+1)**2 + dp(l+1,r)

            for m in range(l+1,r+1):
                if(boxes[l]==boxes[m]):
                    ans = max(ans,dp(m,r,count+1)+dp(l+1,m-1))
            memo[(l,r,count)] = ans
            return ans


        return dp(0,len(boxes)-1)