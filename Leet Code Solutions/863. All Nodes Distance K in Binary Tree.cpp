/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, nullptr, graph);
        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> visited;
        vector<int> result;
        
        q.push({target, 0});
        visited.insert(target);
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            if (distance == K) {
                result.push_back(node->val);
            }
            
            if (distance > K) {
                break;
            }
            
            for (TreeNode* neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, distance + 1});
                }
            }
        }
        
        return result;
    }
    
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (node == nullptr) {
            return;
        }
        
        if (graph.find(node) == graph.end()) {
            graph[node] = vector<TreeNode*>();
        }
        
        if (parent != nullptr) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        
        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }
};
