class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int,int>> event;
        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            event.push_back({startTime[i], endTime[i]});
        }



        vector<int> free;
     
            free.push_back(event[0].first);
        

        for (int i = 1; i < n; i++) {
            int gap = event[i].first - event[i - 1].second;
            free.push_back(gap);
        }

            free.push_back(eventTime - event[n - 1].second);
        

        //   if (free.size() < k+1) return accumulate(free.begin(), free.end(), 0); // use all

        long long sum = 0, maxSum = 0;
        int i=0,j=0;

        while(j<free.size()){
            sum+=free[j];

            if(j-i+1>k+1 && i<n){
                sum-=free[i];
                i++;
            }
            j++;
            maxSum = max(maxSum,sum);
        }

        return maxSum;
    }
};
