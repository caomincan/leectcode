class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> map;
        for(auto& s: strings){
            stringstream buff;
            for(int i = 1;i < s.size();i++){
                int diff = (int)s[i]-s[i-1];
                if(diff < 0) {diff+=26;}
                buff << diff << ",";
            }
            string key = buff.str();
            if(map.find(key) != map.end()){
                map[key].push_back(s);
            }else{
                vector<string> tmp = {s};
                map.insert(make_pair(key,tmp));
            }
        }
        
        vector<vector<string>> ans;
        for(auto& it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};