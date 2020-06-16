class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return helper(lists, 0, static_cast<int>(lists.size())-1);
    }
    
    ListNode* helper(vector<ListNode*>& lists, int st, int ed){
        if(st > ed) return nullptr;
        if(st == ed) return lists[st];
        int mid = st+(ed-st)/2;
        ListNode* left = helper(lists, st, mid);
        ListNode* right = helper(lists, mid+1, ed);
        return merge(left,right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(!left && !right) return nullptr;
        if(!left) return right;
        if(!right) return left;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(left || right){
            if(!left){ // left empty
                p->next = right;
                break;
            }
            if(!right){ // right empty
                p->next = left;
                break;
            }
            if(left->val < right->val){
                p->next = left;
                left = left->next;
            }else{
                p->next = right;
                right = right->next;
            }        
            p = p->next;
        }
        return dummy.next;
    }
};