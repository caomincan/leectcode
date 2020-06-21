class LRUCache {
public:
    struct DLinkedNode {
        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
      };
    
    void addNode(DLinkedNode* node) {
        /**
         * Always add the new node right after head.
         */
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node){
        /**
         * Remove an existing node from the linked list.
         */
        DLinkedNode* prev = node->prev;
        DLinkedNode* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(DLinkedNode* node){
        /**
         * Move certain node in between to the head.
         */
        removeNode(node);
        addNode(node);
    }
    
    DLinkedNode* popTail() {
        /**
         * Pop the current tail.
         */
        DLinkedNode* res = tail->prev;
        removeNode(res);
        return res;
    }

    LRUCache(int capacity) {
        fCapacity = capacity;
        fSize = 0;
        
        head = new DLinkedNode;
        tail = new DLinkedNode;
        
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
    }
    
    int get(int key) {      
        if (cache.find(key) == cache.end()) return -1;
        DLinkedNode* node = cache[key];
        // move the accessed node to the head;
        moveToHead(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
       
        if(cache.find(key) == cache.end()) {
            DLinkedNode* newNode = new DLinkedNode();
            newNode->key = key;
            newNode->value = value;

            cache[key] = newNode;
            addNode(newNode);

            ++fSize;

            if(fSize > fCapacity) {
                // pop the tail
                DLinkedNode* tail = popTail();
                cache.erase(tail->key);
                --fSize;
            }
        } else {
            DLinkedNode* node = cache[key];
            // update the value.
            node->value = value;
            moveToHead(node);
        }
    }
    
    unordered_map<int, DLinkedNode*> cache;
    int fSize;
    int fCapacity;
    DLinkedNode* head;
    DLinkedNode* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */