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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return valid(root);
    }
    
    bool valid(TreeNode* node, TreeNode* upper = nullptr, TreeNode* lower = nullptr){
        if(!node) return true;
        if(upper && node->val >= upper->val){
            return false;
        }
        if(lower && node->val <= lower->val){
            return false;
        }
        return valid(node->left, node, lower) &&
            valid(node->right, upper, node);
    }
};