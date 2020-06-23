class Solution {
public:
    struct Node{
      char val;
      int order;
      char leader;
      bool isVisited;
      bool isRecCall;
      unordered_set<Node*> next;
      Node(char v):
        val(v),
        order(-1),
        leader(-1),
        isVisited(false),
        isRecCall(false)
        {}
    };
    
    int count = 0;
    char lead = 0;
    bool isContainCycle = false;
    
    string alienOrder(vector<string>& words) {
        if(words.empty()) return "";
        string pre_w = words[0];
        // build graph
        vector<Node*> pool;
        unordered_map<char, int> map;
        for(int i =0;i<words.size();i++){
            string& cur = words[i];
            // creating nodes
            for(auto c: cur){
                createNode(c, map, pool);
            }
            if(i == 0) continue;
            int n = min(cur.size(), pre_w.size());
            int k = 0;
            // skip same words
            while(k < n && cur[k] == pre_w[k]) { k++; }
            if(k < n){
                if(!addNode(pre_w[k], cur[k], map, pool)) return "";
            }      
            // first n characters are same
            if(k == n && cur.size() < pre_w.size()) return "";
            pre_w = cur;
        }
#if 0
    // print graph
    for(auto n: pool){
        cout << "node: " << n->val << " to ";
        for(auto nx: n->next){
            cout << nx->val << " ";
        }
        cout << endl;
    }
#endif
        // dfs find topological order
        for(auto n: pool){
            lead = n->val;
            dfs(map, pool, n->val);
        }
        if(isContainCycle) return "";
        // sort based on topological order
        auto comp = [](const Node* a, const Node* b) -> bool {
          return a->order > b->order;  
        };
        sort(pool.begin(), pool.end(), comp);
        // get result;
        stringstream buff;
        for(auto n: pool){
            buff << n->val;
        }
        return buff.str();
    }
    
    void dfs(unordered_map<char, int>& map, vector<Node*>& pool, int cur_c){
        Node* node = pool[map[cur_c]];
        if(node->isVisited) {return;}
        node->isVisited = true;
        node->isRecCall = true;
        //cout << "visit: " << node->val << endl;
        for(auto n: node->next){
            if(n->isRecCall){
                isContainCycle = true;
            }
            dfs(map,pool, n->val);
        }
        // visit current node       
        node->leader = lead;
        count++;
        node->order = count;
        node->isRecCall = false;
        //cout << "process: " << node->val << " count: " << count << endl;
    }
    
    void createNode(char c, unordered_map<char, int>& map, vector<Node*>& pool){
        if(map.find(c) == map.end()){
            Node* node = new Node(c);
            pool.push_back(node);
            map[c] = (int)pool.size() -1;
        }      
    }
    
    bool addNode(char prev_c, char cur_c, unordered_map<char, int>& map, vector<Node*>& pool){
        Node* prev_node = pool[map[prev_c]];
        Node* cur_node  = pool[map[cur_c]];
        // same node wouldn't connect
        if(prev_node == cur_node) return true;
        prev_node->next.insert(cur_node);
        if(!isValid(prev_node, cur_node)) return false;
        return true;
    }
    
    bool isValid(Node* a, Node* b){
        if( (a->next.find(b)!= a->next.end()) 
           && (b->next.find(a) != b->next.end()))
            return false;
        else
            return true;
    }
};