class Solution {
public:
   vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> skills;
        int n = req_skills.size();
        for (int i = 0; i < req_skills.size(); ++i)
            skills[req_skills[i]] = i;
        int m = people.size();
        vector<int> people_skill(m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < people[i].size(); ++j){
                int temp = skills[people[i][j]];
                people_skill[i]|=(1<<temp);
        }
         int s = 1<<n; 
        vector<int> dp(s, INT_MAX);
        vector<int> parent(s,-1);
        vector<int> parent_state(s);
        dp[0] = 0;
        for (int i=0; i <(1<<n); ++i)
            for (int j = 0; j < m; ++j){
                if (dp[i]==INT_MAX) continue;
               int temp = i | people_skill[j];
               if (dp[temp]>dp[i]+1) {parent[temp]=j; parent_state[temp]=i; dp[temp]=dp[i]+1;}         
        }
       
        int temp = (1<<n) -1;
        vector<int> ret;
        while (parent[temp]!=-1){
            ret.push_back(parent[temp]);
            temp = parent_state[temp];
        }
        
        return ret;
    }
};
