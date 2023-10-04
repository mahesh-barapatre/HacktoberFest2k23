class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size(), mod = 1e9+7;
        if(m < n) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = s[0]==t[0];
        for(int i = 1; i < m; i++) {
            if(s[i] == t[0]) dp[i][0] = (dp[i-1][0]%mod + 1)%mod;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(s[i] == t[j]) dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-1]%mod)%mod;
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
