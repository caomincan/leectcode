class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++){
            sums[i+1] += sums[i]+ nums[i];
        }
        for(int count = nums.size(); count > 1;count--){
            for(int pos = 0; pos+count-1 < nums.size();pos++){
                int sum = sums[pos+count]-sums[pos];
                if(k == 0 && sum == 0) return true;
                if(k != 0 && sum % k == 0) return true;
            }
        }
        return false;
    }
};