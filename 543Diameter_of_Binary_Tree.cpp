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
    int max_value = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return max_value-1;
    }
    
    int helper(TreeNode* node){
        if(!node) return 0;
        int leftMax = helper(node->left);
        int rightMax = helper(node->right);
        if(1+leftMax+rightMax > max_value){
            max_value = 1+leftMax+rightMax;
        }
        return max(leftMax+1, rightMax+1);
    }
};