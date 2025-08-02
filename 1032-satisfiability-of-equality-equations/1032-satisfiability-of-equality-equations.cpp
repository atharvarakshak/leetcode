class Solution {
public:
        vector<int> parent,rank;
      
   int find(int x){
        if(parent[x]!=x){
            return parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x,int y){

        int x_p = find(x), y_p = find(y);

        if(rank[x_p]>rank[y_p] ){
            parent[y_p] = x_p;
        }
        else if(rank[x_p]<rank[y_p] ){
            parent[x_p] = y_p;
        }
        else{
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }



    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
        } 

        for(auto s : equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
            
        }
        for(auto s : equations){
            if(s[1]=='!'){
                if(find(s[0]-'a')==find(s[3]-'a')){
                    return false;
                }
            }
            
        }

        return true;
    }

   
};