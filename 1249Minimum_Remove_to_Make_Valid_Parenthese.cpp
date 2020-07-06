class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.empty()) return "";
        vector<bool> keep(s.size(), true);
        stack<int> p;
        // first push into 
        // if top no '(', then delete '('
        for(int i =0; i<s.size(); i++){
            char c = s[i];
            if(c != '(' && c != ')') continue;
            if( c== '(') p.push(i);
            else{
                if(p.empty()) keep[i] = false;
                else {
                    char t = s[p.top()];
                    //assert(t != ')');
                    p.pop();
                }
            }
        }
        //last round delete '(' if reach s end
        while(!p.empty()){
            keep[p.top()] = false;
            p.pop();
        }
        stringstream buf;
        for(int i=0;i<s.size();i++){
            if(keep[i]) buf << s[i];
        }
        return buf.str();
    }
};