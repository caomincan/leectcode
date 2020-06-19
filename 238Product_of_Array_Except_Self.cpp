class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};
        const int n = (int) nums.size();
        vector<int> ans(n,1);  
        vector<int> sub1(n,1);
        sub1[0] = nums[0];
        for(int i= 1;i < n;i++){
            sub1[i] = nums[i]* sub1[i-1];
        }
        vector<int> sub2(n,1);
        sub2[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            sub2[i] = nums[i]*sub2[i+1];
        }
        // calculate result
        for(int i=0;i<n;i++){
            if(i == 0) ans[0] = sub2[1];
            else if(i == n-1) ans[n-1] = sub1[n-2];
            else ans[i] = sub1[i-1]* sub2[i+1];
        }
        return ans;
    }
};