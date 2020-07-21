class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = (int)nums.size();
        int p = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0) continue;
            nums[p++] = nums[i];
        }
        while(p<n) nums[p++] = 0;
    }
};