class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> res,cur,prev;


        res.insert(arr[0]);
        prev.insert(arr[0]);

       for(int i=1;i<n;i++){

            for(auto x : prev){
                cur.insert(arr[i]|x);
                res.insert(arr[i]|x);

            }
            res.insert(arr[i]);
            cur.insert(arr[i]);
            prev = cur;
            cur.clear();
       }
        return res.size();

    }
};