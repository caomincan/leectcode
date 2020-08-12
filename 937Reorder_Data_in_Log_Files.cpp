class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        struct classcomp {
            bool operator() (const string& a, const string& b) const
            {
                int idx1 = 0; int st1 = -1;
                while(idx1 < a.size() && a[idx1] !=' ') { 
                    if(st1 == -1 && (a[idx1] >='0' && a[idx1] <='9' )){
                        st1 = idx1;
                    }
                    idx1++;
                } // first space
                auto value1 = a.substr(idx1+1);
                int idx2 = 0; int st2 = -1;
                while(idx2 < b.size() && b[idx2] != ' ') {
                    if(st2 == -1 && (b[idx2] >='0' && b[idx2] <='9' )){
                        st2 = idx2;
                    }
                    idx2++;
                } // first space
                auto value2 = b.substr(idx2+1);
                if(value1 != value2){
                    return value1 < value2;
                }else{
                    auto key1 = a.substr(0,st1);
                    auto key2 = b.substr(0,st2);
                    if(key1 == key2){
                        int v1 = stoi(a.substr(st1, idx1-st1));
                        int v2 = stoi(b.substr(st2, idx2-st2));
                        return v1 < v2;
                    }else{
                        return key1 < key2;
                    }               
                }
            }
        };
     
        set<string, classcomp> letlogs;
        vector<string> diglogs;
        for(auto& log: logs){
            int idx = 0;
            while(idx < log.size() && log[idx] != ' ') { idx++; }
            if( log[idx+1] >= '0' && log[idx+1] <= '9'){
                diglogs.push_back(log);
            }else{
                letlogs.insert(log);
            }
        }
        vector<string> ans(letlogs.begin(), letlogs.end());
        ans.insert(ans.end(), diglogs.begin(), diglogs.end());
        return ans;
    }
};