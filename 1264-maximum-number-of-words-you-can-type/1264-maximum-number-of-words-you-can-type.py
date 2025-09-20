class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        
        res=[]
        s=""
        a=1
        for c in text:
            if(c==" " and s!="" and a==1):
                res.append(s)
                s=""
            elif(c==" "):
                a=1
            elif(c in brokenLetters):
                s=""
                a=0
            elif(a==1):
                s+=c

        if(s!=""):
            res.append(s)
        return len(res)
