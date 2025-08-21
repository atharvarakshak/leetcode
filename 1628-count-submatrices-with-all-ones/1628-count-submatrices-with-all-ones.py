class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        
        # Step 1: Build heights array (histogram style)
        heights = [[0]*n for _ in range(m)]
        for j in range(n):
            for i in range(m):
                if mat[i][j] == 0:
                    heights[i][j] = 0
                else:
                    heights[i][j] = 1 if i == 0 else heights[i-1][j] + 1

        ans = 0
        
        # Step 2: For each row, count submatrices ending at that row
        for i in range(m):
            for j in range(n):
                if heights[i][j] > 0:
                    min_h = heights[i][j]
                    # Expand leftwards to count rectangles ending at (i, j)
                    for k in range(j, -1, -1):
                        if heights[i][k] == 0:
                            break
                        min_h = min(min_h, heights[i][k])
                        ans += min_h
        return ans