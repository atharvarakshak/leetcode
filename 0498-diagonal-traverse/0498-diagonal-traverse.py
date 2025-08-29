class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ok = True
        i,j=0,0
        n,m = len(mat),len(mat[0])
        c,tot=0,n*m
        arr=[]
        while(tot>0):
            if i<0 and j>=m:
                ok = not ok
                j-=1
                i+=2
                print(i,j,1)
                continue
            elif(i>=n and j<0):
                ok = not ok
                j+=2
                i-=1
                print(i,j,2)
                continue
            elif i<0 :
                ok = not ok
                i=0
                
                print(i,j,3)
                continue
            elif j<0:
                ok = not ok
                j=0
                
                print(i,j,4)
                continue
            elif i>=n:
                ok = not ok
                i=n-1
                j+=2
                print(i,j,5)
                continue
            elif j>=m:
                ok = not ok
                j=m-1
                i+=2
                print(i,j,6)
                continue
                



            arr.append(mat[i][j])

            if ok:
                i-=1
                j+=1
            else:
                i+=1
                j-=1

            print(i,j)

            tot-=1

        return arr

            