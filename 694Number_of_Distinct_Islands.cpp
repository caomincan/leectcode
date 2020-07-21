namespace std{
    template<>
    struct hash<vector<int> >{
        std::size_t operator()(const vector<int>& list) const noexcept {
            std::size_t value = 0;
            for(auto x: list){
                value = (value << 1) ^ hash<int>()(x);
            }
            return value;
        }
    };
}
class Solution {
public:
    int ox = 0;
    int oy = 0;
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        unordered_set<vector<int>, hash<vector<int> > > ans;
        vector<vector<bool>> memo(m, vector<bool>(n, false));
        for(int i=0;i< m; i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 ) continue;
                vector<int> path;
                ox = i; oy=j;
                dfs(grid, i,j , memo, path);
                if(!path.empty()) ans.insert(path);
            }
        }
        return (int)ans.size();
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& memo, vector<int>& path){
        const int m = grid.size();
        const int n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y>= n) return;
        // visited or is not 1'
        if(memo[x][y] || !grid[x][y]) return;
        memo[x][y] = true;
        path.push_back(x-ox);
        path.push_back(y-oy);
        dfs(grid, x-1, y, memo, path);
        dfs(grid, x, y-1, memo, path);
        dfs(grid, x+1, y, memo, path);
        dfs(grid, x, y+1, memo, path);
    }
};