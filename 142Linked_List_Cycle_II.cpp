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
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* q = head;
        // first round
        while(s && q){
            s = s->next;
            q = q->next;
            if(!q){
                return nullptr; // no cycle
            }
            q = q->next;
            if(s == q){
                break; // meet
            }
        }
        if(!q) return nullptr;
        // second round
        s = head;
        while(s!=q){
            s = s->next;
            q = q->next;
        }
        return s;
    }
};