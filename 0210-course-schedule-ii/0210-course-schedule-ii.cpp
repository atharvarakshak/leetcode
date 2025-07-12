class Solution {
public:
    vector<int> topobfs(unordered_map<int, vector<int>>& adj,
                        vector<int>& inDegree, int n) {
        vector<int> res;
        int c = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                res.push_back(i);
                q.push(i);
                c++;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : adj[u]) {
                inDegree[v]--;

                if (inDegree[v] == 0) {
                    res.push_back(v);
                    q.push(v);
                    c++;
                }
            }
        }

        if (c == n) {
            return res;
        }

        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        for (auto it : prerequisites) {
            int u = it[1], v = it[0];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // vector<bool> vis(numCourses, false);

        return topobfs(adj, inDegree, numCourses);
    }
};