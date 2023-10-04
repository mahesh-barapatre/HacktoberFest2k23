class Solution {
public:
    bool memo[32][32][32];
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size())
            return false;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (s1[i] == s2[j]) 
                    memo[1][i][j] = true;
        for (int l = 2; l <= n; l++) 
            for (int i = 0; i <= n - l; i++) 
                for (int j = 0; j <= n - l; j++) 
                    for (int k = 1; k < l; k++) 
                        if ((memo[k][i][j] && memo[l - k][i + k][j + k]) ||
                            (memo[k][i][j + l - k] && memo[l - k][i + k][j])) {
                            memo[l][i][j] = true;
                            break;
        }
        return memo[n][0][0];
    }
};
