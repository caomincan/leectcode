class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = (int)nums.size();
        int sum = 0;
        int count = 0;
        unordered_map<int,int> ans;
        ans[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(ans.find(sum-k) != ans.end()){
                count += ans[sum-k];
            }
            ans[sum]++;
        }
        return count;
    }
};