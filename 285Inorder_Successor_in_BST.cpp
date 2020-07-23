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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return nullptr;
        // case 1 Node p has right child, then min value of its right child is the successor
        auto rightChildMin = findMin(p->right);
        if(rightChildMin) return rightChildMin;
        // case 2 Node p is root and no right child
        if( p == root) return nullptr;
        // case 3 Node p has no right child,  need find its path from root to p
        auto path = findP(root, p);
        // backward order find the its parent just above it
        for(auto it= path.rbegin(); it!= path.rend();++it){
            if((*it)->val > p->val){
                return *it;
            }
        }
        return nullptr;
    }
    
    vector<TreeNode*> findP(TreeNode* n, TreeNode* p){
        vector<TreeNode*> ans;
        while(n && n!=p){
            ans.push_back(n);
            if(n->val > p->val){
                n = n->left;
            }else{
                n = n->right;
            }
        }
        return ans;
    }
    
    TreeNode* findMin(TreeNode* n){
        if(!n) return n;
        while(n->left){
            n = n->left;
        }
        return n;
    }
};