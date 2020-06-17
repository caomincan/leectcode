class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> worklist;
        worklist.push(root);
        while(!worklist.empty()){
            int count = (int)worklist.size();
            while(count > 0){
                TreeNode* p = worklist.front();
                worklist.pop();
                if(p->left) worklist.push(p->left);
                if(p->right) worklist.push(p->right);
                if(count == 1){
                    ans.push_back(p->val);
                }
                count--;
            }
        }
        return ans;
    }
};