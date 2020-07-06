/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        const int m = dims[0];
        const int n = dims[1];
        int c = n-1;
        int r = 0;
        // top to down along the 1
        while(r<m){
            // every row move c to 0
            while(c >= 0 && binaryMatrix.get(r,c)) c--;
            if(c == -1) return 0;
            r++;    
        }
        return c+1 == m ? -1 : c+1;
        
    }
};