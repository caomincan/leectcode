class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> mymap;
        unordered_map<char, char> myrmap; //reverse map
        for(int i= 0; i< s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];
            if(mymap.find(c1) ==  mymap.end()){
                if(myrmap.find(c2) != myrmap.end()) {
                    return false;
                }
                mymap[c1] = c2;
                myrmap[c2] = c1;
            }else{
               if(c2 !=  mymap[c1]){
                   return false;
               } 
            }
        }
        return true;
    }
};