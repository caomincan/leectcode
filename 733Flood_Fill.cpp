class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int m = image.size();
        const int n = image[0].size();
        
        const int oldColor = image[sr][sc];
        if(oldColor != newColor) dfs(image, sr, sc, oldColor, m, n, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, const int color, const int m, const int n, const int newColor){
        if(r<0 || c<0 || r>= m || c>= n) return;
        if(image[r][c] != color) return;
        image[r][c] = newColor;
        dfs(image, r+1, c, color, m, n, newColor);
        dfs(image, r, c+1, color, m, n, newColor);
        dfs(image, r-1, c, color, m, n, newColor);
        dfs(image, r, c-1, color, m, n, newColor);
    }
};