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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto n = s.top();
            s.pop();
            ans.push_back(n->val);
            if(n->right) { s.push(n->right);}
            if(n->left) {s.push(n->left);}
        }
        return ans;
    }
    
    void dfs(TreeNode* node, vector<int>& ans){
        if(!node) return;
        ans.push_back(node->val);
        dfs(node->left, ans);
        dfs(node->right, ans);
    }
};