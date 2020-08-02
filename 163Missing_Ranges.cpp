class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        // O(n) solution
        long cur_lower = lower;
        for(auto n : nums){
            if(n > cur_lower){
                if(n == cur_lower+1)
                    ans.push_back(to_string(cur_lower));
                else
                    ans.push_back(to_string(cur_lower) + "->"+to_string(n-1));
            }
            cur_lower = (long)n+1;
        }
        if(cur_lower < upper){
            ans.push_back(to_string(cur_lower) + "->"+to_string(upper));
        } else if(cur_lower == upper){
             ans.push_back(to_string(cur_lower));
        }
        return ans;
    }
};