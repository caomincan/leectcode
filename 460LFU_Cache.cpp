class LFUCache {
public:
    struct DListNode{
        DListNode(int key, int value):
            k(key),
            val(value),
            freq(0),
            next(nullptr),
            prev(nullptr){
                
            }
        int k;
        int val;
        int freq;
        DListNode* next;
        DListNode* prev;
    };
    
    LFUCache(int capacity): 
        cap(capacity),
        size(0),
        head(new DListNode(0,0)),
        tail(new DListNode(0,0))
    {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cap == 0) return -1;
        if(data.find(key) == data.end()) return -1;
        else{
            DListNode* node = data[key];
            node->freq++;
            adjustOrder(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(data.find(key) == data.end()){
            DListNode* node = new DListNode(key, value);
            size++;
            if(size > cap){
                removeTail();
                size--;
            }
            data[key] = node;
            DListNode* prevNode = tail->prev;
            prevNode->next = node;
            tail->prev = node;
            node->prev = prevNode;
            node->next = tail;
            adjustOrder(node);
        } else{
            DListNode* node = data[key];
            node->val = value;
            node->freq++;
            adjustOrder(node);
        }
    }
    
    void adjustOrder(DListNode* node){
        DListNode* p = node;
        while(p != head && p->freq <= node->freq){
            p = p->prev;
        }
        // disconnect node
        DListNode* pre = node->prev;
        DListNode* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
        // insert node
        DListNode* nextNode = p->next;
        p->next = node;
        node->prev = p;
        nextNode->prev = node;
        node->next = nextNode;        
    }
    
    void removeTail(){
        if(tail->prev == head) return; // already empty
        DListNode* toRemove = tail->prev;
        DListNode* prevNode = toRemove->prev;
        prevNode->next = tail;
        tail->prev = prevNode;
        // erase key
        data.erase(toRemove->k);
        delete toRemove;
    }
    
    DListNode* head;
    DListNode* tail;
    int cap;
    int size;
    unordered_map<int, DListNode*> data;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */