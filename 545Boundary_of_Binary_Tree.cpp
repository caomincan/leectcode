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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {}; // empty tree
        if(isLeaf(root)) return {root->val};
        // left boundary
        vector<int> lefts;
        TreeNode* leftMost = printLeft(root->left, lefts);
        // right boundary
        vector<int> rights;
        TreeNode* rightMost = printRight(root->right, rights);
        // bfs find all leafs
        queue<TreeNode*> work; work.push(root);
        vector<int> ans;
        ans.push_back(root->val);
        ans.insert(ans.end(), lefts.begin(), lefts.end());
        printLeaf(root, ans, leftMost, rightMost);
        ans.insert(ans.end(), rights.rbegin(), rights.rend());
        return ans;
    }
    
    bool isLeaf(TreeNode* n){
        return n && !n->left && !n->right;
    }
    
    void printLeaf(TreeNode* node, vector<int>& ans, TreeNode* leftMost, TreeNode* rightMost){
        if(!node) return;
        if(isLeaf(node)){
            if(node != leftMost && node != rightMost){
                ans.push_back(node->val);
            }
            return;
        }
        printLeaf(node->left, ans, leftMost, rightMost);
        printLeaf(node->right, ans, leftMost, rightMost);
    }
    
    TreeNode* printLeft(TreeNode* node, vector<int>& left){
        if(!node) return nullptr;
        while(!isLeaf(node)){
            left.push_back(node->val);
            node = node->left ? node->left : node->right;
        }
        left.push_back(node->val);
        return node;
    }
    
    TreeNode* printRight(TreeNode* node, vector<int>& right){
        if(!node) return nullptr;
        while(!isLeaf(node)){
            right.push_back(node->val); // reverse order
            node = node->right ? node->right: node->left;
        }
        right.push_back(node->val);
        return node;
    }
};