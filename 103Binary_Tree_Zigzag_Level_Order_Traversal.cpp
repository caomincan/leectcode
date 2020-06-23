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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        // init
        deque<TreeNode*> worklist;
        worklist.push_back(root);
        bool leftToRight = true;
        
        vector<vector<int>> ans;
        while(!worklist.empty()){
            int count = (int)worklist.size();
            vector<int> cur_level_list;
            while(count>0){
                TreeNode* node = nullptr;
                if(leftToRight){
                    node = worklist.front();
                    worklist.pop_front();
                    if(node->left)  worklist.push_back(node->left);
                    if(node->right) worklist.push_back(node->right);                   
                }else{
                    node = worklist.back();
                    worklist.pop_back();
                     if(node->right) worklist.push_front(node->right);    
                     if(node->left)  worklist.push_front(node->left);
                }
                cur_level_list.push_back(node->val);
                count--;
            }
            ans.push_back(cur_level_list);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};