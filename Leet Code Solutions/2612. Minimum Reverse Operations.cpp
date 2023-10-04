
class Solution {
public:
    pair<int, int> getRange(int x, int n, int k)
    {
        int l = max(x - k + 1, 0), r = min(x, n - k);
        int L = 2 * l + k - 1 - x, R = 2 * r + k - 1 - x;
        return {L, R};
    }
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k)
    {
        set<int> E[2];
        for(int i = 0; i < n; i++) E[i & 1].insert(i);
        int B = (int)banned.size();
        for(int i = 0; i < B; i++) E[banned[i] & 1].erase(banned[i]);
        vector<int> ans(n, -1);
        queue<int> q;
        q.push(p);
        ans[p] = 0;
        E[p & 1].erase(p);
        while(!q.empty())
        {
            int x = q.front(); q.pop();
            pair<int, int> R = getRange(x, n, k);
            set<int>& cur = E[R.first & 1];
            auto it = cur.lower_bound(R.first);
            while(it != cur.end() && *it <= R.second)
            {
                ans[*it] = ans[x] + 1;
                q.push(*it);
                it = cur.erase(it);
            }
        }
        return ans;
    }
};
