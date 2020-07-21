/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        queue<Node*> worklist;
        worklist.push(node);
        
        unordered_map<Node*,Node*> map;
        Node* root = new Node(node->val);
        map[node] = root;
        // working
        while(!worklist.empty()){
            int count = worklist.size();
            while(count > 0){
                Node* cur = worklist.front();
                worklist.pop();
                if(map.find(cur) == map.end()){
                    map[cur] = new Node(cur->val);
                }
                Node* copy = map[cur];
                for(auto n: cur->neighbors){
                    if(map.find(n) == map.end()){
                        map[n] = new Node(n->val);
                        worklist.push(n);
                    }
                    Node* neigh_copy = map[n];
                    copy->neighbors.push_back(neigh_copy);
                }
                count--; 
            }
        }
        return root;
    }
};