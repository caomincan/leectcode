class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        
        sort(nums.begin(), nums.end());
        const int n = static_cast<int>(nums.size());        
        for(int i = 0; i< n-2;i++){
            if(i != 0 && nums[i-1] == nums[i]) {continue;} // remove depulicates
            int target = -nums[i];
            int lIdx = i+1; int rIdx = n-1;
            while(lIdx < rIdx){
                int sum = nums[lIdx]+nums[rIdx];
                if( sum == target){
                    ans.push_back({nums[i], nums[lIdx], nums[rIdx]});
                    // this part is tricky go pass duplicate one but need one more ++ and --
                    while(lIdx < rIdx && nums[lIdx] == nums[lIdx+1]) lIdx++;
                    while(lIdx < rIdx && nums[rIdx] == nums[rIdx-1]) rIdx--;
                    lIdx++;
                    rIdx--;
                } else if( sum > target){
                    rIdx--;
                } else{
                    lIdx++;
                }
            }
        }
        return ans;
    }
};