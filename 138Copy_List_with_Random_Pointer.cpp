/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map; // old node <-> new node
        Node dummy(0);
        Node* p = &dummy;
        while(head){
            // whether create new node
            if(map.find(head) == map.end()){
                Node* pN = new Node(head->val);
                map.insert(make_pair(head,pN));
            }
            p->next = map[head];            
            p = p->next;
            // handle random
            if(head->random){
                if(map.find(head->random) == map.end()){
                    // not exsist
                    Node* pR = new Node(head->random->val);
                    map.insert(make_pair(head->random, pR));               
                }
                p->random = map[head->random];
            }
            head = head->next;
        }
        return dummy.next;
    }
};