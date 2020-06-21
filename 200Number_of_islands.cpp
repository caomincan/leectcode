class Solution {
public:
    // union find
    struct node{
      node* leader;
      int rank;
      node(node* l, int r):
        leader(l),
        rank(r)
        {}
      node():
        leader(this),
        rank(0)
        {}
    };
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        const int m = (int)grid.size();
        const int n = (int)grid[0].size();
        
        vector<vector<node*>> map(m, vector<node*>(n, nullptr));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '0') continue;
                node* cur = getOrCreate(map, i, j);
                if(i-1 >=0 && grid[i-1][j] == '1'){
                    node* tmp = getOrCreate(map, i-1, j);
                    union_node(cur, tmp);
                }
                if(i+1 < m && grid[i+1][j] == '1'){
                    node* tmp = getOrCreate(map, i+1, j);
                    union_node(cur, tmp);
                }
                if(j-1>= 0 && grid[i][j-1] == '1'){
                    node* tmp = getOrCreate(map, i, j-1);
                    union_node(cur, tmp);
                }
                if(j+1 < n && grid[i][j+1] == '1'){
                    node* tmp = getOrCreate(map, i, j+1);
                    union_node(cur, tmp);
                }
               
            }
        }
        // count
        unordered_set<node*> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                node* cur = map[i][j];
                if(cur == nullptr) continue;
                //cout << "i= " << i << " j= " << j << " leader: " << find(cur) <<endl;
                ans.insert(find(cur));
            }
        }
        return (int)ans.size();
    }
    
    node* getOrCreate(vector<vector<node*>>& map, int x ,int y){
        if(!map[x][y]) map[x][y] = new node;
        return map[x][y];
    }
    
    node* find(node* n){     
        if(n->leader != n){  n->leader = find(n->leader);}
        return n->leader;
    }
    
    void union_node(node* a, node* b){
        node* la = find(a);
        node* lb = find(b);
        
        if(la != lb){
             if(la->rank > lb->rank){
                lb->leader = la;
            } else if ( la->rank < lb->rank){
                la->leader = lb;
            } else{
                la->rank++;
                lb->leader = la;
            }
        }       
    }
    
    
};