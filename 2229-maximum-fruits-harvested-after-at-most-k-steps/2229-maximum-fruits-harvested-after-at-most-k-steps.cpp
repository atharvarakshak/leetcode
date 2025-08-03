class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefSum(n), pos(n);


        for(int i=0;i<n;i++){
            prefSum[i] = fruits[i][1] + (i>0 ? prefSum[i-1]:0);
            pos[i] = fruits[i][0];
        }

        int maxF=0;

        for(int d=0;d<=k/2;d++){
            int rem = k-2*d;
            int i = startPos-d;
            int j = startPos+rem;

            int left = lower_bound(pos.begin(),pos.end(),i)-pos.begin();
            int right = upper_bound(pos.begin(),pos.end(),j)-pos.begin()-1;

            if(left<=right){

                int res1 = prefSum[right]-(left>0 ? prefSum[left-1] : 0);
                maxF=max(maxF,res1);
            }
             rem = k-2*d;
             i = startPos-rem;
             j = startPos+d;

             left = lower_bound(pos.begin(),pos.end(),i)-pos.begin();
             right = upper_bound(pos.begin(),pos.end(),j)-pos.begin()-1;

             if(left<=right){

                 int res2 = prefSum[right]-(left>0 ? prefSum[left-1] : 0);
                maxF=max(maxF,res2);
            }
        }

        return maxF;
    }
};