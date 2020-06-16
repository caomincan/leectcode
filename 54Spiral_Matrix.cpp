class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        
        int rst = 0; int red = m-1;
        int cst = 0; int ced = n-1;
        
        vector<int> ans;
        while(rst <= red && cst <= ced){
            // from left to right
            for(int i=cst;i<=ced;i++) { ans.push_back(matrix[rst][i]);}
            // from top to bottom
            for(int i=rst+1;i<=red;i++) { ans.push_back(matrix[i][ced]);}          
            if(cst < ced && rst < red){
                // from right to left
                for(int i=ced-1;i>cst;i--) { ans.push_back(matrix[red][i]);}
                // from bottom to top
                for(int i=red; i> rst; i--) { ans.push_back(matrix[i][cst]);}
            }            
            
            rst++;
            red--;
            cst++;
            ced--;
        }
        return ans;
    }
};