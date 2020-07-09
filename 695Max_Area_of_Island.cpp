class Solution {
public:
    int count = 0;
    int max_count = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<bool>> memo(m, vector<bool>(n, false));
        for(int i = 0; i< m; i++){
            for(int j =0;j < n;j++){
                if(!grid[i][j]) continue;
                count = 0;
                dfs(grid, i, j, memo);
                if(count > max_count) max_count = count;
            }
        }
        return max_count;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& memo){
        const int m = grid.size();
        const int n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y>= n) return;
        // visited or is not 1'
        if(memo[x][y] || !grid[x][y]) return;
        count++;
        memo[x][y] = true;
        dfs(grid, x-1, y, memo);
        dfs(grid, x, y-1, memo);
        dfs(grid, x+1, y, memo);
        dfs(grid, x, y+1, memo);
    }
};