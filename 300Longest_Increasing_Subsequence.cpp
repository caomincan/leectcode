class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <=1) return nums.size();
        const int n = (int)nums.size();
        vector<int> memo(n, 1);
        int ans = 1;
        for(int i=1;i <n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    memo[i] = max(memo[i], memo[j]+1);
                }
            }
            if(memo[i] > ans){
                ans = memo[i];
            }
        }
        // find maxmimum
        return ans;
    }
};