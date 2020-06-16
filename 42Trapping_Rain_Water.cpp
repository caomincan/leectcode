class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height);
        vector<int> right(height);
        // find left max, looking its left
        for(int i = 1; i< height.size();i++){
            left[i] = max(left[i-1], left[i]);
        }
        // find right max, looking its right
        for(int i = static_cast<int>(height.size())-2; i>=0;i--){
            right[i] = max(right[i+1], right[i]);
        }
        // calculating
        int sum = 0;
        for(int i=0;i<height.size();i++){
            sum += min(left[i],right[i])-height[i];
        }
        return sum;
    }
};