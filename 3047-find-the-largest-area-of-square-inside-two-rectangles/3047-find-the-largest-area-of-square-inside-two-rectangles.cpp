class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSqSize=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                // x overlap
                int leftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int rightX = min(topRight[i][0], topRight[j][0]);

                int overlapWidth = rightX-leftX;

                // y overlap

                int bottomY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int topY = min(topRight[i][1], topRight[j][1]);

                int overlapHeight = topY-bottomY;

                if(overlapWidth>0 && overlapHeight>0){
                    long long side = min(overlapWidth,overlapHeight);
                    maxSqSize = max(maxSqSize,side);
                }
            }
        }

        return maxSqSize*maxSqSize;
    }
};