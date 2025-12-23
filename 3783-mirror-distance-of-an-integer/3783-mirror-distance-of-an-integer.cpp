class Solution {
public:
    int mirrorDistance(int n) {
        string  s2=to_string(n);
        reverse(s2.begin(),s2.end());
        int num = stoi(s2);
        return abs(n-num);

    }
};