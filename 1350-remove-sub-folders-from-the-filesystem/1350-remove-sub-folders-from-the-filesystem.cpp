class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();

        vector<string> res;
        // unordered_set<string> folderSet(folder.begin(),folder.end());

            sort(folder.begin(),folder.end());

            for(auto &f : folder){
                if(res.empty()){
                    res.push_back(f);
                }
                else{
                    string prev = res.back();
                    if(f.find(prev)==0 && f.size()>prev.size()  && f[prev.size()] == '/'){
                        continue;
                    }
                    else{
                        res.push_back(f);
                    }
                }

            }
                return res;
    }
};