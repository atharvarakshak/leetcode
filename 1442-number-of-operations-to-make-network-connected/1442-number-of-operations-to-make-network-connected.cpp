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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        if(connections.size()<n-1)return -1;

        for(auto &conn: connections){
            int a = conn[0];
            int b = conn[1];
            cout<<parent[a]<<" "<<parent[b]<<endl;
            if(find(a)!=find(b)){
                Union(a,b);
                n--;
            }
        }

        return n-1;
    }
};