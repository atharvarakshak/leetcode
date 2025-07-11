class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        vector<int> free;
        
        vector<pair<int,int>> event;

        
        for (int i = 0; i < n; i++) {
            event.push_back({startTime[i], endTime[i]});
        }


     
         free.push_back(event[0].first);
        

        for (int i = 1; i < n; i++) {
            int gap = event[i].first - event[i - 1].second;
            free.push_back(gap);
        }

            free.push_back(eventTime - event[n - 1].second);


            int m= free.size();
            vector<int> maxFreeLeft(m,0),maxFreeRight(m,0);
            maxFreeLeft[0]=0;
            maxFreeRight[m-1]=0;
            int maxL=0,maxR=0;
            for(int i=1;i<m;i++){
                maxFreeLeft[i] = max(free[i-1],maxFreeLeft[i-1]);
            }
             for(int i=m-2;i>=0;i--){
                maxFreeRight[i] = max(free[i+1],maxFreeRight[i+1]);
            }

            for(int i=1;i<m;i++){
                int x = (event[i-1].second - event[i-1].first);
                if(x<= max(maxFreeLeft[i-1],maxFreeRight[i])){
                    res= max(res,x+free[i-1]+free[i]);
                }
                else{
                     res= max(res,free[i-1]+free[i]);
                }
            }


        
        return res;
    }
};