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
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        inorder(root, L, R);
        return sum;
    }
    
    void inorder(TreeNode* node, const int L, const int R){
        if(!node) return;
        if(L< node->val ) inorder(node->left, L, R);
        if(node->val >= L && node->val <= R){
            sum += node->val;
        }
        if(R > node->val) inorder(node->right, L, R);
    }
    

};