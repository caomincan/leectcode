class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty()) return {};
        // keep indicies
        unordered_map<int, int> record;
        for(int i = 0; i< nums.size(); i++){
            int t = target - nums[i];
            if(record.find(nums[i]) != record.end()){
                return {record[nums[i]], i};
            }else{
                record.insert(make_pair(t, i));
            }
        }
        return {};
    }
};