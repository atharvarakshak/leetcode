class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(x<arr[0]){
            return {arr.begin(),arr.begin()+k};
        }
        if(x>arr[n-1]){
            return {arr.end()-k,arr.end()};
        }
        // vector<pair<int,int>> v;
      

        // for(int i=0;i<n;i++){
        //     v.push_back({abs(arr[i]-x),arr[i]});
        // }

        // sort(v.begin(),v.end());
        vector<int> res;
        // for(int i=0;i<k;i++){
        //     res.push_back(v[i].second);
        // }
        //     sort(res.begin(),res.end());

        // return res;

        int l=0,r=n-k;

        while(l<r){
            int m = l + (r-l)/2;

            if(x-arr[m] > arr[m+k] -x ){
                l = m+1;
            }
            else{
                r=m;
            }
        }

        return vector<int> (arr.begin()+l,arr.begin()+l+k);



    }
};