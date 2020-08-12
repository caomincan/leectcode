class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, q = 0;
        do{
            s = nums[s];
            q = nums[nums[q]];
        }while(s!= q);
        // second round
        s= 0;
        while(s!=q){
            s = nums[s];
            q = nums[q];
        }

        return s;
    }
};