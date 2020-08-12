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
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* node){
        if(!node) return nullptr;
        if(!node->next) return node;
        // split two
        // count total number of nodes
        int n = 0;
        ListNode* p = node;
        while(p){
            p = p->next;
            n++;
        }
        int i = 0;
        p = node;
        while(i<(n-1)/2){
            p = p->next;
            i++;
        }
        ListNode* left = node;
        ListNode* right = p->next;
        p->next = nullptr; // break the chain
        left = mergeSort(left);
        right = mergeSort(right);
        // combine solution
        ListNode dummy(0);
        p = &dummy;
        while(left && right){
            if(left->val <= right->val){
                p->next = left;
                left = left->next;
            }else{
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if(left){
            p->next = left;
        } else if(right){
            p->next = right;
        }
        return dummy.next;
    }
};