class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for(auto& s: strs){
            string key(s);
            sort(key.begin(), key.end());
            auto it = group.find(key);
            if(it != group.end()){
                it->second.push_back(s);
            }else{
                vector<string> tmp = {s};
                group.insert(make_pair(key, tmp));
            }
        }
        vector<vector<string> > ans;
        for(auto pair: group){
            ans.push_back(move(pair.second));
        }
        return ans;
    }
};