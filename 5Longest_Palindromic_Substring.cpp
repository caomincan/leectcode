class Solution {
public:
    string longestPalindrome(string s) {
		// pretty slow maybe top-down method can work
        if(s.empty()) return s;
        const int n = static_cast<int>(s.size());
        vector<vector<bool>> dp(n+1, vector<bool>(n, false));
        dp[0] = vector<bool>(n, true);
        // start bottom-up
        string ans(1, s[0]);
        for(int k=1;k<=n;k++){ // how long is the string
            for(int i = 0; i< n;i++){
                // init value
                if(k==1) { dp[k][i] = true; continue;}
                if(i+k <= n && s[i] == s[i+k-1]){ // within length and 
                    dp[k][i] = dp[k-2][i+1];
                }
                if(dp[k][i] && k>ans.size()){
                    ans = s.substr(i,k);
                }
            }
        }
        return ans;
    }
};