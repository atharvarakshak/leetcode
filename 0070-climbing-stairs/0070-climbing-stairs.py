class Solution:
    
   
   

    def climbStairs(self, n: int) -> int:
        @lru_cache(None)
        def solve(n):

            if(n==0 or n==1):
                return 1
            
            return solve(n-1)+solve(n-2)

        return solve(n)