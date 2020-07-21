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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(!root) return ans;
        dfs(root, ans);
        return ans;
    }
    
    void dfs(TreeNode* node, vector<vector<int> >& ans, int level = 0){
        if(!node) return;
        // not exsit
        if(level >= ans.size()){
            ans.reserve(level+1);
            ans.emplace(ans.begin()+level, vector<int>());
        }
        ans[level].push_back(node->val);
        dfs(node->left, ans, level+1);
        dfs(node->right, ans, level+1);
    }
};