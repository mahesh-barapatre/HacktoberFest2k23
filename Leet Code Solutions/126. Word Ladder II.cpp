class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> mpp;
    void dfs(vector<string> v, string beginWord){
        string last = v[v.size() - 1];
        if(last == beginWord){
            reverse(v.begin(), v.end());
            ans.push_back(v);
            return;
        }
        int lev = mpp[last];
        for(int i = 0; i < last.size(); i++){
            char org = last[i];
            for(char c = 'a'; c <= 'z'; c++){
                last[i] = c;
                if(mpp.count(last) && mpp[last] + 1 == lev){
                    v.push_back(last);
                    dfs(v, beginWord);
                    v.pop_back();
                }
            }
            last[i] = org;
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        mpp.clear();
        ans.clear();
        unordered_set<string> s;
        for(auto& it : wordList)s.insert(it);
        queue<string> q;
        q.push(beginWord);
        if(s.find(beginWord) != s.end())s.erase(beginWord);
        if(s.find(endWord) == s.end())return {};
        int dis = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string temp = q.front();
                q.pop();
                mpp[temp] = dis;
                if(temp == endWord)goto label;
                for(int i = 0; i < temp.size(); i++){
                    char org = temp[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        temp[i] = c;
                        if(s.find(temp) != s.end()){
                            s.erase(temp);
                            q.push(temp);
                        }
                    }
                    temp[i] = org;
                }
            }
            dis++;
        }
        label:
        vector<string> v = {endWord};
        dfs(v, beginWord);
        return ans;
    }
};
