class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return INT_MIN;
        int max_sum = nums[0];
        int sum = 0;
        for(auto n: nums){
            sum = max(n, sum+n);
            if(sum> max_sum){
                max_sum = sum;
            }
        }
        return max_sum;
    }
};