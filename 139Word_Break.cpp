class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty()) return s.empty();
        vector<int> memo(s.size()+1, -1);
        memo[0] = 1;
        return dp(s, s.size(), wordDict, memo);
    }
    
    // top-down
    bool dp(string& s, int cur, vector<string>& wordDict, vector<int>& memo){
        if(memo[cur] != -1){
            return memo[cur] == 1;
        }
        
        bool isAny = false;
        for(auto& w: wordDict){
            if((int)w.size() > cur) { continue;}
            const int n = (int)w.size();
            int prev = cur-n;            
            if(s.substr(prev, n) == w){
                 isAny |= dp(s, prev, wordDict, memo);
            }
        }
        
        memo[cur] = isAny? 1: 0;
        return memo[cur];
    }
};