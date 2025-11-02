class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
         sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int first=intervals[0][0], last = intervals[0][1];

        if(n==1)return intervals;

        for(int i=1;i<n;i++){
            if(intervals[i][0]>last){
                ans.push_back({first,last});
                first = intervals[i][0];
                last = intervals[i][1];
            }
            else{
                first = min(first,intervals[i][0]);
                last = max(last,intervals[i][1]);
            }
        }
        ans.push_back({first,last});
        return ans;
    }
};