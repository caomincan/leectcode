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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* construct(vector<int>& preorder, int pbegin, int pend, vector<int>& inorder, int inbegin, int inend){
        if(pbegin > pend) return nullptr;
        if(pbegin == pend) return new TreeNode(preorder[pbegin]);
        
        int self_val = preorder[pbegin];
        TreeNode* self = new TreeNode(self_val);
        int idx = find(inorder.begin()+inbegin, inorder.begin()+inend, self_val) - inorder.begin();
        int numLeft = idx-inbegin;
        self->left = construct(preorder, pbegin+1, pbegin+numLeft, inorder, inbegin, idx-1);
        self->right = construct(preorder, pbegin+numLeft+1, pend, inorder, idx+1, inend);
        return self;
    }
};