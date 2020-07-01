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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > ans;
        map<int, vector<int> > mid; // middle variables to store value
        bfs(root, mid);
        for(auto& p: mid){
            ans.push_back(move(p.second));
        }
    
        return ans;
    }
    
    void bfs(TreeNode* node, map<int, vector<int> >& res){
        if(!node) return;
        queue<pair<TreeNode*, int>> work;
        work.push(make_pair(node, 0));
        
        while(!work.empty()){
            int count = work.size();
            while(count > 0){
                auto p = work.front();
                work.pop();
                TreeNode* n = p.first;
                int x = p.second;
                if(res.find(x) == res.end())
                    res[x] = vector<int>();
                auto& list = res[x];
                list.push_back(n->val);
                // children
                if(n->left) work.push(make_pair(n->left, x-1));
                if(n->right) work.push(make_pair(n->right, x+1));
                count--;
            }
        }
    }
};