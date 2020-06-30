class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty()) return true;
        
        const int n = (int) graph.size();
        vector<int> memo(n, -1);
        
        for(int i =0;i<n;i++){
            if(memo[i] != -1) continue; //already visited
            stack<int> work;
            work.push(i);
            memo[i] = 0;
            while(!work.empty()){
                int u = work.top(); work.pop();
                for(auto v: graph[u]){
                    if(memo[v] == -1){
                        work.push(v);
                        memo[v] = memo[u] ^ 1;
                    } else if( memo[v] == memo[u]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};