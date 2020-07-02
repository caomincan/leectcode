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
    unordered_set<int> ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, int> parents; // node to target its distance
        find(root, target, parents);
        for(auto& p : parents){
            if(p.second > K) continue;
            if(p.second == K) ans.insert(p.first->val);
            dfs(p.first, parents, 0, K-p.second);            
        }
        return vector<int>(ans.begin(), ans.end());
    }
    
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& parents, int d, const int K){
        if(!node) return;
        if(d > K) return;
        if(d == K) {
            ans.insert(node->val);
            return;
        }
        if(parents.find(node->left) == parents.end()) dfs(node->left, parents, d+1, K);
        if(parents.find(node->right) == parents.end()) dfs(node->right, parents, d+1, K);
    }
    
    int find(TreeNode* node,const TreeNode* target, unordered_map<TreeNode*, int>& parents){
        if(!node) return -1;
        if(node == target){
            parents[node] = 0;
            return 0;
        }
        int l = find(node->left, target, parents);
        if( l != -1) {
            parents[node] = l+1;
            return l+1;
        }
        int r = find(node->right, target, parents);
        if( r != -1){
            parents[node] = r+1;
            return r+1;
        }
        return -1;
    }
};