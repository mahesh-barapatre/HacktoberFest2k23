/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int m=INT_MIN;

    int find_max_sum(TreeNode* root){   //maxsum 
        if(!root)
        return 0;

        return root->val+max(0,max(find_max_sum(root->left),find_max_sum(root->right)));
    }

    void solve(TreeNode* root){   //postorder
        if(root){
            solve(root->left);
            solve(root->right);
            int ls=find_max_sum(root->left);
            int rs=find_max_sum(root->right);

            if(ls<0)
            ls=0;
            if(rs<0)
            rs=0;

            m=max(ls+rs+root->val,m);
        }
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return m;
    }
};
