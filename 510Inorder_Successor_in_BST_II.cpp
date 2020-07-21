/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return nullptr;
        Node* p = node->parent;
        if(!p) return findMin(node->right);
        while( p->parent && p->val < node->val){
            p = p->parent;
        }
        Node* rightMin = findMin(node->right);
        if(rightMin && rightMin->val> node->val){
            return rightMin;
        }else{
            return p->val>node->val? p : nullptr;
        }
    }
    
    Node* findMin(Node* node){
        if(!node) return nullptr;
        while(node->left){
            node = node->left;
        }
        return node;
    }
};