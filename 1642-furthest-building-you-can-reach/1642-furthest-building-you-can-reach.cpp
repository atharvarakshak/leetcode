class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> p;
        
       
        int i=0,diff=0;
        for( i=0;i<heights.size()-1;i++){
            diff = heights[i+1]-heights[i];
            if(heights[i+1]<=heights[i]){
                continue;
            }
            else{
                bricks-=diff;
                p.push(diff);
                if(bricks<0){
                    bricks += p.top();
                    p.pop();
                    ladders--;
                }

            }
            if(ladders<0){
                break;
            }
        }
        return i;

    }
};