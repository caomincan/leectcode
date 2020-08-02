class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int time = 0;
        while(true){
            auto next_grid(grid);
            bool isDirty = false;
            for(int i = 0; i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j] == 2){
                        // top
                        if(i-1 >= 0 && next_grid[i-1][j] == 1) {
                            isDirty = true;
                            next_grid[i-1][j] = 2;
                        }
                        // left
                        if(j-1 >= 0 && next_grid[i][j-1] == 1){
                            isDirty = true;
                            next_grid[i][j-1] = 2;
                        }
                        // bottom
                        if(i+1 < grid.size() && next_grid[i+1][j] == 1){
                            isDirty = true;
                            next_grid[i+1][j] = 2;
                        }
                        // right
                        if(j+1 < grid[0].size() && next_grid[i][j+1] == 1){
                            isDirty= true;
                            next_grid[i][j+1] = 2;
                        }
                    }
                }
            }
            if(!isDirty) {break;}
            time++;
            grid = next_grid;
        }
        return anyFresh(grid) ? -1 : time;
    }
    
    bool anyFresh(vector<vector<int>>& grid){
        for(int i = 0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) {
                    return true;
                }
            }
        }
        return false;
    }

};