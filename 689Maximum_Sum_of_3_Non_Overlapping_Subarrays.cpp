class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<long long> sums(nums.size()-k+1, 0);
        long long subtotal = 0;
        for(int i=0;i<nums.size();i++){
            subtotal += nums[i];
            if(i>=k){
                subtotal -= nums[i-k];
            }
            if(i>=k-1){
                sums[i-k+1] = subtotal;
            }
        }
        
        vector<int> left(sums.size(), 0);
        int best = 0;
        for(int i=0;i< sums.size();i++){
            if(sums[i]>sums[best]) best = i;
            left[i] = best;
        }
        
        vector<int> right(sums.size(), 0);
        best = sums.size()-1;
        for(int i = sums.size()-1;i>=0;i--){
            if(sums[i] >= sums[best]) best = i;
            right[i] = best;
        }
        
        vector<int> ans(3,-1);
        for(int j=k;j<sums.size()-k;j++){
            int i = left[j-k];
            int l = right[j+k];
            if(ans[0]==-1 || sums[i]+sums[j]+sums[l] > sums[ans[0]]+sums[ans[1]]+sums[ans[2]]){
                ans = {i,j, l};
            }
        }
        
        return ans;
    }
};