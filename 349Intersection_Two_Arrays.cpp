class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> total;
        vector<int> ans;
        for(auto n: nums1){
            total.insert(n);
        }
        // find result
        for(auto n: nums2){
            if(total.find(n) != total.end()){
                ans.push_back(n);
                total.erase(n);
            }
        }
        return ans;
    }
};