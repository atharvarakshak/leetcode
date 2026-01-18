class Solution {
public:

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int> hf(hFences.size()+2), vf(vFences.size()+2);
         long long MOD = 1000000007;
        int h = hf.size(), v= vf.size();
        int maxSide=-1;
        hf[0]=1;
        for(int i=0;i<hFences.size();i++){
            hf[i+1]=hFences[i];
        }
        hf[hFences.size()+1]=m;
        vf[0]=1;
        for(int i=0;i<vFences.size();i++){
            vf[i+1]=vFences[i];
        }
        vf[vFences.size()+1]=n;
        sort(hf.begin(),hf.end());
        sort(vf.begin(),vf.end());
        unordered_set<int> s1;
        for(int i=0;i<h;i++){
            for(int j=i+1;j<h;j++){
                s1.insert(hf[j]-hf[i]);
            }
        }

        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                int vSide=vf[j]-vf[i];
                if(s1.find(vSide)!=s1.end()){
                    maxSide = max(maxSide, vSide);

                }
            }
        }

        if(maxSide==-1)return -1;

        long long area = 1LL * maxSide * maxSide;
        return (int)(area % MOD);
    }
};