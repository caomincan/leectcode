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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p1 = &dummy;
        ListNode* p2 = head;
        while(p2 && p2->next){
            ListNode* next_p1 = p2;
            ListNode* next_p2 = p2->next->next;
            // swap
            p1->next = p2->next;
            p2->next->next = p2;
            p2->next = next_p2;
            // update
            p1= next_p1;
            p2 = next_p2;
        }
        return dummy.next;
    }
};