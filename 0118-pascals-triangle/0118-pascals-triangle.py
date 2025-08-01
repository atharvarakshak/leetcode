class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        v=[[1]]

        if(numRows==1):
            return v
        
        v.append([1,1])

        if(numRows==2):
            return v

        for i in range(2,numRows):
            nw = []

            nw.append(1)

            for j in range(1, i):
                nw.append(v[i-1][j-1] + v[i-1][j])

            nw.append(1)

            v.append(nw)


        return v

