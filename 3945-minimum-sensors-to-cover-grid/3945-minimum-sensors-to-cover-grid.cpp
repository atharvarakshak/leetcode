class Solution {
public:
    int minSensors(int n, int m, int k) {
        return ceil((double)n/((2*k)+1)) * ceil((double)m/((2*k)+1));
    }
};