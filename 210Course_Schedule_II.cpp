class Solution {
public:
    struct Node {
      int val;
      int leader;
      int order;
      unordered_set<int> next;
      
      Node(int value):
        val(value),
        leader(-1),
        order(-1)
        {}
    };
    
    int lead = 0;
    int count = 0;
    bool hasCycle = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> pool(numCourses, nullptr);
        for(int i=0;i<numCourses; i++){
            pool[i] = new Node(i);
        }
        for(auto& p: prerequisites){
            pool[p[1]]->next.insert(p[0]);
        }
        // dfs topological sort and detect cycle
        vector<bool> memo(numCourses, false);
        vector<bool> rec(numCourses, false);
        for(int i=0;i< numCourses;i++){
            lead = i;
            dfs(pool, i, memo, rec);
        }
        if(hasCycle) return {};
        // sorting
        auto comp = [](const Node* a, const Node* b) -> bool {
          return a->order > b->order;  
        };
        sort(pool.begin(), pool.end(), comp);
        // answer
        vector<int> ans;
        for(auto n : pool){
            ans.push_back(n->val);
        }
        return ans;
    }
    
    void dfs(vector<Node*>& pool, int cur, vector<bool>& memo, vector<bool>& rec){
        if(memo[cur]) return;
        memo[cur] = true;
        rec[cur] = true;
        for(auto n: pool[cur]->next){
            if(rec[n]){
                hasCycle = true;
            }
            dfs(pool, n, memo, rec);
        }
        pool[cur]->leader = lead;
        pool[cur]->order = ++count;
        rec[cur] =false;
    }
};