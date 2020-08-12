/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* p = & dummy;
        // working on head
        while(head){
            ListNode* st = head;
            ListNode* ed = head;
            int count = 0;
            while(ed && count < k-1){
                count++;
                ed = ed->next;
            }
            // not enough k
            if(count < k-1 || !ed){
                break;
            }
            // e.g. 2->1->3, k=2, st = 2, ed=1, one node previous 3
            head = ed->next;
            ed->next = nullptr; // break chain
            ListNode* newHead = reverse(st);
            // connect to ans
            p->next = newHead;
            p = st;
        }
        if(head){
            p->next = head;
        }
        return dummy.next;
    }
    
    ListNode* reverse(ListNode* n){
        if(!n) return nullptr;
        if(!n->next) return n;
        ListNode* newHeader = reverse(n->next);
        n->next->next = n;
        n->next = nullptr;
        return newHeader;
    }
};