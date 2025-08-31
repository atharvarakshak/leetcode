class Solution:

    
        


    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n,m =len(grid),len(grid[0])
        @lru_cache(None)
        def dfs( i: int, j:int, d:int  )->int:
            if(i==n-1 and j==m-1):
                return 1

            if(i==n or j==m):
                return 0

            if(grid[i][j]==0):
                return (dfs(i+1,j,1) + dfs(i,j+1,0))%MOD

            ans=0
            if(d==1):
                return dfs(i,j+1,0)%MOD
            else:
                return dfs(i+1,j,1)%MOD

        return dfs(0,0,-1)%MOD
        