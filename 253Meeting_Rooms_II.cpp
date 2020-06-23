class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& a, const vector<int>& b) -> bool {
            if(a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> ans;
        for(auto& p : intervals){
            if(ans.empty()){
                ans.push_back(p[1]);
                continue;
            }
            
            bool isInsert = false;
            for(auto& end_time: ans){
                if(end_time <= p[0]) {
                    end_time = p[1];
                    isInsert = true;
                    break;
                }
            }
            if(!isInsert) ans.push_back(p[1]);
        }
        return ans.size();
    }
};