class Solution {
public:
    int dp[2001];
    bool isPalindrome(const std::string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }

    int minCut(const std::string& s) {
        int n = s.length();
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            dp[i] = i;
        }

        for (int i = 1; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        dp[i] = std::min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
