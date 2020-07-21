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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > ans;
        queue<TreeNode*> worklist;
        worklist.push(root);
        while(!worklist.empty()){
            int count = worklist.size();
            ans.emplace(ans.end(), vector<int>()); // init empty vector
            while(count>0){
                auto n = worklist.front();
                worklist.pop();
                ans.back().push_back(n->val);
                if(n->left) worklist.push(n->left);
                if(n->right) worklist.push(n->right);
                count--;
            }
        }
        return vector<vector<int> >(ans.rbegin(), ans.rend());
    }
};