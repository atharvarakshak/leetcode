class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        n = len(points)
        def area(p,q,r):
            return 0.5 * abs(p[0]*q[1]+q[0]*r[1]+r[0]*p[1]
                           -p[1]*q[0]-q[1]*r[0]-r[1]*p[0])

        maxi=0
        for i in range(0,n):
            for j in range(1,n):
                for k in range(2,n):
                    maxi = max(maxi,area(points[i],points[j],points[k]))

        return maxi