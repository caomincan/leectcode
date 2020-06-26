class Solution {
public:
    Solution(vector<int>& nums): data(nums) {
    }
    
    int pick(int target) {
        vector<int> res;
        auto found = find(data.begin(), data.end(), target);
        while(found != data.end()){
            res.push_back(static_cast<int>(found-data.begin()));
            found = find(found+1, data.end(), target);
        }
        if(res.empty()) return -1;
        int idx = rand()%static_cast<int>(res.size());
        return res[idx];
    }
    
    vector<int>& data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */