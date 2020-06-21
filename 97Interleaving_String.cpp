class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.empty()) return s1.empty()&&s2.empty();
        const int n1 = (int)s1.size();
        const int n2 = (int)s2.size();
        const int n3 = (int)s3.size();
        if(n1+n2 != n3) return false;
        vector<vector<int>> memo(n1, vector<int>(n2,-1));
        return dp(s1,n1-1,s2,n2-1,s3,n3-1,memo);
    }
    
    bool dp(string& s1, int p1, 
            string& s2, int p2, 
            string& s3, int p3,
            vector<vector<int>>& memo){
        if(p3 < 0) return true;
        if(p1 < 0 ){
           return s2.substr(0,p2+1) == s3.substr(0, p3+1);
        }
        if(p2 < 0){
           return s1.substr(0,p1+1) == s3.substr(0, p3+1);
        }
        if(memo[p1][p2] != -1){
            return memo[p1][p2] == 1;
        }
        
        char cur = s3[p3];
        char a = '*';
        char b = '*';
        if(p1>=0 && p2 >=0){
            a = s1[p1];
            b = s2[p2];
        }else if(p1 >=0){
            a = s1[p1];
        }else if(p2 >= 0){
            b = s2[p2];
        }
        
        if(a != cur && b!= cur){
            memo[p1][p2] = 0;
        } else if(a == cur && b == cur) {
            memo[p1][p2] = dp(s1,p1-1,s2,p2,s3,p3-1, memo)
                || dp(s1,p1,s2,p2-1,s3,p3-1, memo);
        } else if(a== cur){
            memo[p1][p2] = dp(s1,p1-1,s2,p2,s3,p3-1, memo);
        } else {
            memo[p1][p2] = dp(s1,p1,s2,p2-1,s3,p3-1, memo);
        }
        return memo[p1][p2] == 1;
    }
};