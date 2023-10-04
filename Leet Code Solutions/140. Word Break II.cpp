class Solution {
public:
    bool isValid(string& ans, string& s) {
        string temp = ans;
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        return temp == s;
    }
    void solve(int i, string& s,vector<string>& wordDict, string& ans, vector<string>& res) {
        if (i >= s.size()) {
            if (isValid(ans, s)) {
                res.push_back(ans);
            }
            return;
        }
        for (string word : wordDict) {
            int n = word.size();
            if (i + n <= s.size() && s.substr(i, n) == word) {
                string temp = ans;
                if (!temp.empty())
                    temp += " ";
                temp += word;
                solve(i + n, s, wordDict, temp, res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string ans;
        solve(0, s, wordDict, ans, res);
        return res;
    }
};
