class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        int n = nums.size();
        for(auto x : nums){
            if(x>=0){
                pos.push_back(x);
            }
        }
        if(pos.size()==0)return nums;

        int d = k%pos.size();

        queue<int> q;

        for(auto x : pos){
            q.push(x);
        }
        // rotate 
        while(d--){
            int tmp = q.front();
            q.pop();

            q.push(tmp);
        }
       
        
        
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i]=q.front();
                q.pop();
            }
        }


        return nums;


    }
};