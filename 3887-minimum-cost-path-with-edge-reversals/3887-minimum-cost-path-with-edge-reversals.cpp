class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {


        vector<vector<pair<int,int>>> adj(n);

        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],2*e[2]});
        }

        vector<int> dist(n,INT_MAX);

        // pair<dist_so_far, node>
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();

            int d = u.first, node = u.second ;

            if(dist[node]!=INT_MAX)continue;
            dist[node] = d;
            for(auto &v : adj[node]){
                if(dist[v.first]==INT_MAX){
                    pq.push({v.second+d,v.first});
                }
            }
        }

        if(dist.back()==INT_MAX)return -1;

        return dist.back();
    }
};