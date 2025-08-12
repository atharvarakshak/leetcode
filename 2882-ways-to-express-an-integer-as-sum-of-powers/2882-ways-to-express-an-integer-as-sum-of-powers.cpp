#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> power;
    vector<vector<int>> dp;

    int solve(int n, int x, int idx, int sum) {
        if (sum == n) return 1;
        if (sum > n || idx >= (int)power.size()) return 0;

        if (dp[idx][sum] != -1) return dp[idx][sum];

        // Option 1: take idx^x
        int take = solve(n, x, idx + 1, sum + power[idx]) % MOD;
        // Option 2: skip idx^x
        int skip = solve(n, x, idx + 1, sum) % MOD;

        return dp[idx][sum] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        // Precompute all powers <= n
        for (int i = 1; pow(i, x) <= n; i++) {
            power.push_back((long long)pow(i, x));
        }

        dp.assign(power.size(), vector<int>(n + 1, -1));
        return solve(n, x, 0, 0);
    }
};
