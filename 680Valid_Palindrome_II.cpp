class Solution {
public:
    bool validPalindrome(string s) {
        if(s.empty()) return true;
        return helper(s, 0, (int)s.size()-1);
    }
    
    bool helper(string& s, int l, int r, bool isSkip1C = false){
        if(l >= r) return true;
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                if(isSkip1C) return false;
                else{
                    return helper(s, l, r-1, true)
                        || helper(s, l+1, r, true);
                }
            }
        }
        return true;
    }
};