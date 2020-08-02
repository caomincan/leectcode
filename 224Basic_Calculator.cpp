class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        int idx = 0;      
        return cal_helper(s, idx);
    }
    
    bool skip_space(string& s, int& idx){
        while(idx< s.size() && s[idx] == ' ') { idx++; }
        return idx >= s.size();
    }
    
    int cal_helper(string& s, int& idx){
        int sum = 0;
        while(idx < s.size()){
            // check if ')'
            if(s[idx] == ')'){
                idx++;
                return sum;
            }
            // skip leading space
            if(skip_space(s, idx)) {break;}
            // check + or -
            int sign = 1;
            if(s[idx] == '+' || s[idx] == '-'){
                if(s[idx] == '-') { sign = -1; }
                idx++;
            }
            // skip space
            if(skip_space(s, idx)) {break;}
            // if ( need push previous result
            if(s[idx] == '('){
                sum += sign* cal_helper(s, ++idx);
                continue;
            }
            // skip space
            if(skip_space(s, idx)) {break;}
            // find number
            int st = idx;
            while(idx < s.size() && is_num(s[idx])) { idx++; }
            int n = stoi(s.substr(st, idx-st));
            sum += sign* n;
            // skip space
            if(skip_space(s, idx)) {break;}
            // check if ')'
            if(s[idx] == ')'){
                idx++;
                return sum;
            }
        }
        return sum;
    }
    
    bool is_num(char c){
        return c >= '0' && c <= '9';
    }
};