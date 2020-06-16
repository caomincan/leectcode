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
    int sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return sum;
    }
    
    int helper(TreeNode* node){
        if(!node) return 0;
        int left = max(helper(node->left), 0);
        int right = max(helper(node->right), 0);
        
        sum = max(sum, node->val + left+right);
        
        return node->val+ max(left, right);
    }
};