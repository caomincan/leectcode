class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        const int n = (int)s.size();
        const int lp = (int)p.size();
        if(lp> n || lp==0) return ans;
      
        // initilize key
        vector<int> key(26, 0);
        for(auto c: p){
            key[c-'a']++;
        }
        // init first 0-lp number
        vector<int> check(26,0);
        for(int i=0;i<lp-1;i++){
            check[s[i]-'a']++;
        }
        for(int i=lp-1;i< n ;i++ ){
            check[s[i]-'a']++;
            bool isEqual = true;
            for(int j=0;j<26;j++){
                if(key[j] != check[j]) {
                    isEqual = false;
                    break;
                }
            }
            if(isEqual){
                ans.push_back(i-lp+1);
            }
            check[s[i-lp+1]-'a']--;
        }
        return ans;
    }
    
};