class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        vector<int> arr={-1,-1};

        while(start<=end){
            int mid = start + (end - start) / 2;
           if(nums[mid]==target){
             arr[0]=mid;
             end=mid-1;
           }
           else if(nums[mid]<target){
                    start = mid+1;
            }
            else{
                    end = mid-1;
            }

        }
        int l=0, r=nums.size()-1;

        while(l<=r){
            int mid = l + (r - l) / 2;
           if(nums[mid]==target){
             arr[1]=mid;
             l=mid+1;
           }
           else if(nums[mid]<target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }

        }

        return arr;
    }
};