class Solution {
    void finalize(int m, vector<vector<int>>& edges) {
        for (auto& e : edges) {
            if (e[2] < 0) {
                if (m > 0) {
                    --m;
                    e[2] = 1;
                } else {
                    e[2] = 1234567890;
                }
            }
        }
    }
    
    vector<int> spfa(int n, int s, const vector<vector<pair<int, int>>> &con) {
        vector<int> d(n, -1);
        vector<bool> mark(n);
        d[s] = 0;
        priority_queue<pair<int, int>> q;
        q.push({0, s});
        while (!q.empty()) {
            const int x = q.top().second;
            q.pop();
            if (mark[x]) {
                continue;
            }
            mark[x] = true;
            for (const auto& v : con[x]) {
                const int y = v.first, w = v.second;
                if (mark[y] || (d[y] >= 0 && d[y] <= d[x] + w)) {
                    continue;
                }
                d[y] = d[x] + w;
                q.push({-d[y], y});
            }
        }
        return d;
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<int> ind;
        for (int i = 0; i < edges.size(); ++i) { 
            if (edges[i][2] < 0) {
                ind.push_back(i);
            }
        }
        int left = 0, right = ind.size();
        while (left <= right) {
            const int mid = (left + right) >> 1;
            vector<vector<pair<int, int>>> con(n);
            int m = mid;
            for (const auto & e : edges) {
                int w = e[2];
                if (e[2] < 0) {
                    if (m <= 0) {
                        continue;
                    }
                    --m;
                    w = 1;
                }   
                con[e[0]].push_back({e[1], w});
                con[e[1]].push_back({e[0], w});
            }
            const vector<int> &d1 = spfa(n, source, con);
            if (d1[destination] == target) {
                finalize(mid, edges);
                return edges;
            }
            if (d1[destination] >= 0 && d1[destination] < target) {
                right = mid - 1;
                continue;
            }
            const vector<int> &d2 = spfa(n, destination, con);
            for (int t = mid; t < ind.size(); ++t) {
                const int i = ind[t];
                if (d1[edges[i][0]] >= 0 && d2[edges[i][1]] >= 0 && d1[edges[i][0]] + d2[edges[i][1]] < target) {
                    edges[i][2] = target - (d1[edges[i][0]] + d2[edges[i][1]]);
                    finalize(mid, edges);
                    return edges;
                }
                if (d1[edges[i][1]] >= 0 && d2[edges[i][0]] >= 0 && d1[edges[i][1]] + d2[edges[i][0]] < target) {
                    edges[i][2] = target - (d1[edges[i][1]] + d2[edges[i][0]]);
                    finalize(mid, edges);
                    return edges;
                }
            }
            left = mid + 1;
        }
        
        return {};
    }
};
