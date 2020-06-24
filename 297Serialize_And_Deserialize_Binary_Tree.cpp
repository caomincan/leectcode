/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        queue<TreeNode*> Q;
        stringstream buff;
        buff << to_string(root->val);
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()){
            int count = Q.size();
            while(count> 0){
                TreeNode* n = Q.front();
                Q.pop();
                if(!n){
                    buff << ",n";
                }else{
                    buff << "," << to_string(n->val);
                    Q.push(n->left);
                    Q.push(n->right);
                }
                count--;
            }
        }
        //cout<< buff.str() << endl;
        return buff.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "n") return nullptr;
        vector<TreeNode*> list;
        int idx =0;
        while(idx < data.size()){
            // skip to ','
            int st = idx;
            while(idx < data.size() && data[idx] != ',') { idx++;}
            string num = data.substr(st, idx-st);
            if(num == "n"){
                list.push_back(nullptr);
            }else{
                list.push_back(new TreeNode(stoi(num)));
            }
            idx++;
        }
        // reconstruct tree
        TreeNode* root = list[0];
        idx = 0;
        int check = 1;
        while(idx < list.size()){
            int count = 0;
            int st = idx;
            int not_null = 0;
            for(int i = 0; i+st< list.size() && i< check;i++){
                if(!list[st+i]) continue;
                int left_idx = st+check+ not_null*2;
                int right_idx = st+check+ not_null*2+1;
                if(left_idx < list.size() && list[left_idx]){
                    list[st+i]->left = list[left_idx];
                }
                if(right_idx < list.size() && list[right_idx]){
                    list[st+i]->right = list[right_idx];
                }
                count +=2;
                not_null++;
            }
            idx+= check;
            check = count;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));