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
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {       
        dfs(root, p, q);
        return ans;
    }
    
    bool dfs(TreeNode* node, const TreeNode* p, const TreeNode* q)
    {
        if(!node) return false;
        int left = dfs(node->left, p, q) ? 1 : 0;
        int right = dfs(node->right, p, q) ? 1 : 0;
        
        int mid = (node == p || node == q) ? 1: 0;
        
        if(left+right+mid >= 2){
            ans = node;
        }
        
        return (left+right+mid> 0);
    }
};