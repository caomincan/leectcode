class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sorting method
        // sort(nums.begin(),nums.end(), greater<int>());
        return RSelect(nums, 0, (int)nums.size()-1,k);
    }
    
    int RSelect(vector<int>& nums, int st, int ed, int k){
        if(st == ed) return nums[st];
        int p = st+(ed-st)/2;
        swap(nums, st, p);
        // from st to ed-1 find pivot position
        int l = st+1; int r = ed;
        int pivot = nums[st];
        while(l<=r){           
            while(r>st && nums[r] <= pivot)  {r--;}
            while(l <= r && nums[l] > pivot) {l++;}
            if(l<r){
                swap(nums, l ,r);
            }
        }
        // l will be the position that
        swap(nums, r, st);
        if(r+1 == k) return nums[r];
        else if( k < r+1) return RSelect(nums, st, r-1, k);
        else return RSelect(nums, r+1, ed, k);
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};