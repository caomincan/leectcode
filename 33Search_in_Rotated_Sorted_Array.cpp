class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        const int n = (int)nums.size();
        // no duplicate exists in the array
        if(nums[0] <= nums[n-1]) return binary_search(nums, 0, n-1, target);
        int l= 0, r = n-1;
        while(l < r){
            if(nums[l] == target) return l;
            if(nums[r] == target) return r;
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[l] < nums[mid]){
                if(target <= nums[mid] && target >= nums[l]) return binary_search(nums, l, mid, target);
            }
            if(nums[mid] < nums[r]){
                if(target >= nums[mid] && target <= nums[r]) return binary_search(nums, mid, r, target);
            }
            r--;
        }
        return nums[l] == target ? l : -1;
    }
    
    int binary_search(vector<int>& nums, int l, int r, const int target){
        if(l > r) return -1;
        while(l < r){
            int mid = l + (r-l)/2;
            if( target == nums[mid]){
                return mid;
            } else if(target > nums[mid]){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};