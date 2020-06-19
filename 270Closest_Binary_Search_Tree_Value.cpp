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
    TreeNode* up_bound = nullptr;
    TreeNode* low_bound = nullptr;
    int closestValue(TreeNode* root, double target) {
        search(root, target);
        if(up_bound && low_bound){
            return abs(up_bound->val-target) < abs(low_bound->val-target) ? up_bound->val : low_bound->val;
        }else if(up_bound){
            return up_bound->val;
        }else if(low_bound){
            return low_bound->val;
        }else{
            return -1;
        }
    }
    
    void search(TreeNode* node, const double target){
        if(!node) return;
        while(node){
            double val = (double)node->val;
            if(target > val){
                if(!low_bound || node->val>low_bound->val) low_bound = node;
                node = node->right;
            }else{
                if(!up_bound || node->val < up_bound->val) up_bound = node;
                node = node->left;
            }
        }
    }
};