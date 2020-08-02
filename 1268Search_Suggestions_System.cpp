class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // build database
        unordered_map<string, vector<string>> data;
        for(auto& str : products){
            stringstream buff;
            for(auto c: str){
                buff << c;
                data[buff.str()].push_back(str);
            }
        }
        // sort each product in order
        for(auto& p : data){
           sort(p.second.begin(), p.second.end(), [](const string& a, const string& b){ return a < b;}); 
        }
        // get result
        vector<vector<string>> ans;
        stringstream buff;
        for(auto c: searchWord){
            buff << c;
            string key = buff.str();
            if(data.find(key) != data.end()){
                auto& list = data[key];
                if(list.size() > 3){
                    vector<string> tmp( list.begin(), list.begin()+3);
                    ans.push_back(tmp);
                }else{
                    ans.push_back(list);
                }
            }else{
                ans.push_back({});
            }
        }
        return ans;
    }
};