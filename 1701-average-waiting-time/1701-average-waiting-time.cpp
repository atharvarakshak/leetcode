class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int fin=(customers[0][0]+customers[0][1]),st=customers[0][0],arr;
        double wt=fin-customers[0][0];
        for(int i=1;i<customers.size();i++){
            if(customers[i][0]<=fin){
                st=fin;
                fin=st+customers[i][1];
            }
            else{
                st = customers[i][0];
                fin = st+customers[i][1];
            }
            cout<<st<<" "<<fin<<endl;
            wt+=(fin-customers[i][0]);
        }
        return (double)wt/customers.size();

    }
};