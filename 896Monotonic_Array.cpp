class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() <=1) return true;
        int pre_diff = 0;
        for(int i=1;i<A.size();i++){
            int diff = A[i]-A[i-1];
            if(diff != 0){
                if(diff * pre_diff < 0) return false;
                pre_diff = diff;
            }
        }
        return true;
    }
};