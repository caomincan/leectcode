/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        // conect chidren
        if(root->left && root->right){
            root->left->next = root->right;
        }        
        // check edge
        if(root->next && root->right){
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
/*
class Solution {
public:
    Node* connect(Node* root) {
        if(!root || isLeaf(root)) return root;
        // conect chidren
        root->left->next = root->right;
        // check grand child
        if(!isLeaf(root->left) && !isLeaf(root->right)){
            root->left->right->next = root->right->left;
        }
        if(root->next && !isLeaf(root->right) && !isLeaf(root->next->left)){
            root->right->right->next = root->next->left->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
    
    bool isLeaf(Node* node){
        return node && !node->left && !node->right;
    }
};*/