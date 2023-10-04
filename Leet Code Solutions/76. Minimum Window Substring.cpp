class Solution {
public:
    bool check(vector<int> &freq_t, vector<int> &freq_s)
    {
        for(int i=0;i<256;i++)
        {
            if(freq_t[i] != 0 && freq_t[i] > freq_s[i])
            {
                return false;
            }
        }   
        return true;
    }
    string minWindow(string s, string t) 
    {
        vector<int> freq_t(256,0);
        vector<int> freq_s(256,0);
        int l = 0;
        int r = 0;
        string ans = "";
        int cnt = INT_MAX;
        if(s.size() < t.size())
        {
            return "";
        }
        for(int i=0;i<t.size();i++)
        {
            freq_t[t[i]]++;
        }
        while(r < s.size())
        {
            freq_s[s[r]]++;

            while(l <= r && (freq_t[s[l]] == 0 || freq_s[s[l]] > freq_t[s[l]]))
            {
                freq_s[s[l]]--;
                l++;
            }
            if(check(freq_t, freq_s))
            {
                if(cnt > r - l + 1)
                {
                    cnt = r - l + 1;
                    ans = s.substr(l,cnt);
                }

                freq_s[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
