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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        // orederd map, first level is x
        // second level is y
        map<int, map<int,  vector<int>, greater<int> > > tree; 
        traversal(root, tree);
        vector<vector<int>> ans;
        for(auto& y: tree){
            ans.push_back(vector<int>());
            auto& list = ans.back();
            for(auto& p: y.second){
                auto& n = p.second;
                sort(n.begin(), n.end());
                list.insert(list.end(), n.begin(), n.end());
            }
        }
        return ans;
    }
    
    void traversal(TreeNode* node, map<int, map<int, vector<int>, greater<int> > >& tree, int x = 0, int y = 0){
        if(!node) return;
        if(tree.find(x) == tree.end())
            tree[x] = map<int, vector<int>, greater<int> >();
        auto& tree_x = tree[x];
        if(tree_x.find(y) == tree_x.end())
            tree_x[y] = vector<int>();
        auto& tree_x_y = tree_x[y];
        tree_x_y.push_back(node->val);
        // for child
        traversal(node->left, tree, x-1, y-1);
        traversal(node->right, tree, x+1, y-1);
    }
};