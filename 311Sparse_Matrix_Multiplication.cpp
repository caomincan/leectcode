class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || B.empty()) return {};
        const int nRow = A.size();
        const int nCol = B[0].size();
        const int kBit = A[0].size();
        vector<unsigned int> rows;
        vector<unsigned int> cols;
        // prepare A
        for(int i=0;i<nRow;i++){
            vector<int>& cur = A[i];
            unsigned int val = 0x00000000;
            for(int j=0;j< kBit;j++){
                val <<= 1;
                if(cur[j]) val |= 0x00000001;               
            }
            rows.push_back(val);
        }
        // prepare B
        for(int i=0;i<nCol;i++){
            unsigned int val = 0x00000000;
            for(int j=0;j<kBit;j++){
                val <<= 1;
                if(B[j][i]) val |= 0x00000001;                
            }
            cols.push_back(val);
        }
        
        vector<vector<int>> ans(nRow, vector<int>(nCol, 0));
        for(int i=0;i<nRow;i++){
            for(int j=0;j<nCol;j++){
                unsigned int check = (rows[i] & cols[j]);
                if(!check) continue;
                int sum = 0;
                for(int k= kBit-1;k>=0;k--){
                    unsigned int bit = check & 0x00000001;
                    check >>=1;
                    if(!bit) continue;
                    // has value
                    sum += A[i][k]*B[k][j];
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};