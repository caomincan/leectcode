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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        // a better solution is to use stack 
        // and implement in order travesal 
        // not covert tree to queue
        in_order(data, root);
    }
    
    /** @return the next smallest number */
    int next() {
        int val = data.front();
        data.pop();
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !data.empty();
    }
    
    queue<int> data;
    
    void in_order(queue<int>& data, TreeNode* node){
        if(!node) return;
        in_order(data, node->left);
        data.push(node->val);
        in_order(data, node->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */