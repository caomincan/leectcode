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
    int max_diff = 0;
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return max_diff;
    }
    
    tuple<bool,int, int> dfs(TreeNode* node){
        if(!node) return make_tuple(false, -1, -1);
        bool ltest; int lval_min; int lval_max;
        tie(ltest, lval_min, lval_max) = dfs(node->left);
        bool rtest; int rval_min; int rval_max;
        tie(rtest, rval_min, rval_max) = dfs(node->right);
        int diff = 0; int min_child =0; int max_child = 0;
        if(!ltest && !rtest){
            return make_tuple(true, node->val, node->val);
        } else if(ltest && rtest){
            min_child = min(lval_min, rval_min);
            max_child = max(lval_max, rval_max);
          
        } else if(ltest){
            min_child = lval_min;
            max_child = lval_max;
        } else{
            min_child = rval_min;
            max_child = rval_max;
        }
        diff = max(abs(node->val- min_child), abs(node->val- max_child));
        if(diff > max_diff){
            max_diff = diff;
        }
        return make_tuple(true, min(node->val, min_child), max(node->val, max_child));
    }
};