class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        if(nums.empty()) return k;
         int pl = 0, pr = (int)nums.size()-1;
        if(k > countMissing(pr, nums))
            return nums[pr]+k - countMissing(pr, nums);
       
        while(pl != pr){
            int mid = pl+(pr-pl)/2;
            int missing = countMissing(mid, nums);
            if(missing < k){
                pl = mid+1;
            } else{
                pr = mid;
            } 
        }
        return nums[pl-1]+k - countMissing(pl-1, nums);
    }
    
    int countMissing(int idx, vector<int>& nums){
        return nums[idx]-nums[0]-idx;
    }
};