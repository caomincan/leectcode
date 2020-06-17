class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int l = 0; int r = static_cast<int>(s.size())-1;
        while(l<r){
            while(l<r && !isChar(s[l]) ) { l++;}
            while(l<r && !isChar(s[r]) ) { r--;}
            if(l<r && toLower(s[l]) != toLower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    bool isChar(char c){
        // number belongs to character e.g. 0P is false
        if( (c>='a' && c <='z') || (c >='A' && c <= 'Z') || (c >= '0' && c <='9')){
            return true;
        }else{
            return false;
        }
    }
    
    char toLower(char c){
        if(c >='A' && c <= 'Z'){
            return (char)(c-'A'+'a');
        }else{
            return c;
        }
    }
};