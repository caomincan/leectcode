class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return word.empty();
        if(word.empty()) return false;
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        for(int i= 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0] == board[i][j] && backtracking(board, word, 0, i,j)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, string& word, int w_cur = 0, int r = 0, int c = 0){
        if(w_cur == static_cast<int>(word.size())){
            return true;
        }
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board[0].size());
        // beyond the boundary
        if(r<0 || c <0 || r >= m || c >= n){
            return false;
        }
        
        bool ans = false;
        if(word[w_cur] == board[r][c]){
            char w = word[w_cur];
            board[r][c] = '&';
            if(backtracking(board, word, w_cur+1, r+1, c) ||
              backtracking(board, word, w_cur+1, r, c+1) ||
              backtracking(board, word, w_cur+1, r-1, c) ||
              backtracking(board, word, w_cur+1, r, c-1))
            {
                ans = true;
            }
            board[r][c] = w;
        }
        return ans;
    }
};