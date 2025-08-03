class Solution {
public:
 vector<int> parent,rank;

    int find(int x){
        if(x != parent[x]){
            return parent[x] = find(parent[x]); 
        }

        return parent[x];
    }

    void Union(int x,int y){
        int x_parent = find(x), y_parent = find(y);
        if(x_parent==y_parent)return;

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
       
        parent.resize(n);
        rank.resize(n,0);
        unordered_map<int,int> mp;


        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &edg: edges){
            int a = edg[0], b= edg[1];

            if(parent[a]!=parent[b]){
                Union(a,b);
            }
        }

        for(int i=0;i<n;i++){
            int x = find(i);
            mp[x]++;
        }
        int rem=n;
        long long res=0;

        for(auto &m : mp){
            long long size = m.second;
            res += (long long)size*(rem-size);
            rem-=size;
        }

        return res;
    }
};