class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;
        int n = classes.size();
        for(int i=0;i<n;i++){
            int a = classes[i][0];
            int b = classes[i][1];
            double inc = (double)(a+1)/(b+1) - (double)(a)/(b);;

            pq.push({inc,{a,b}});

            
        }

        while(extraStudents--){
           auto [delta, ab] = pq.top(); pq.pop();
            int a = ab.first, b = ab.second;
            a++, b++;  
            double inc = (double)(a+1)/(b+1) -(double)(a)/(b);

             pq.push({inc,{a,b}});

        }
        double sum=0.00000;

        while(!pq.empty()){
            auto [delta, ab] = pq.top(); pq.pop();
            int a = ab.first, b = ab.second;
       
    

            sum+=(double)(a)/(b);
        }
        return (double)(sum)/(n);

    }
};