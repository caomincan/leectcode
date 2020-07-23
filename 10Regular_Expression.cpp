class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }
    
    bool helper(string& s, int sIdx, string& p, int pIdx){
        if(pIdx >= p.size()) return sIdx >= s.size();
        bool is_first_match = sIdx < s.size() && (
            s[sIdx] == p[pIdx] || isDot(p[pIdx]) );
        
        if(pIdx+1 < p.size() && isStar(p[pIdx+1])){
            // have star
            return (is_first_match && helper(s, sIdx+1, p, pIdx))
                || helper(s, sIdx, p, pIdx+2);
        }else{
            return is_first_match && helper(s, sIdx+1, p, pIdx+1);
        }
        
    }
            
    bool isDot(char c){
        return c == '.';
    }
            
    bool isStar(char c){
        return c == '*';
    }
};