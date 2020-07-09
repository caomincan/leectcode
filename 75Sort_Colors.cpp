class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() <=1 ) return;
        int p1 = 0, p2 = (int)nums.size()-1;
        int cur = 0;
        while(cur <= p2){
            if(nums[cur] == 0) swap(nums, p1++, cur++);
            else if(nums[cur] == 2) swap(nums, p2--, cur);
            else cur++;
        }
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};