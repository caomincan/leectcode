class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        
        int shorterDim = min(matrix.size(), matrix[0].size());
        
        for(int i=0;i<shorterDim;i++){
            bool vFound = binarySearch(matrix, target, i, true);
            bool hFound = binarySearch(matrix, target, i, false);
            if(vFound || hFound){
                return true;
            }
        }
        return false;
    }
    
    bool binarySearch(vector<vector<int>>& matrix, int target, int start, bool vertical) {
        int lo = start;
        int hi = vertical ? (int)matrix[0].size()-1 : (int)matrix.size()-1;

        while (hi >= lo) {
            int mid = (lo + hi)/2;
            if (vertical) { // searching a column
                if (matrix[start][mid] < target) {
                    lo = mid + 1;
                } else if (matrix[start][mid] > target) {
                    hi = mid - 1;
                } else {
                    return true;
                }
            } else { // searching a row
                if (matrix[mid][start] < target) {
                    lo = mid + 1;
                } else if (matrix[mid][start] > target) {
                    hi = mid - 1;
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};