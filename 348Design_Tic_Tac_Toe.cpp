class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) :  records(2, vector<int>(2*n+2, 0)){
        num = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        vector<int>& record = records[player-1];
        // check diagnol
        if(row == col){
            record[0]++;
            if(record[0] == num ) return player;
        }
        // check another diag
        if(col == -row+num-1){
            record[1]++;
            if(record[1] == num) return player;
        }
        // check row
        record[row+2]++;
        if(record[row+2] == num) return player;
        // check column
        record[col+2+num]++;
        if(record[col+2+num] == num) return player;
        // no win
        return 0;
    }
    
    int num;
    vector<vector<int>> records;
    
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */