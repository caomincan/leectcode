/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* d = head;
        while(s && d){
            s = s->next;
            d = d->next;
            if(!d){
                return false;
            }
            d = d->next;
            if(s == d){
                break;
            }
        }
        return d != nullptr;
    }
};