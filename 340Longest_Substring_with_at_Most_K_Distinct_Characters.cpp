class Solution {
public:
    int max_value = 0;
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        unordered_map<char, int> check;
        int p1 = 0, p2 = 0;
        while(p2 < s.size()){
            // increasing p2 once p2 reach k for check
            while(p2 < s.size() 
                  &&  (check.size() < k || (check.size() == k && check.find(s[p2]) != check.end()))){             
                check[s[p2]]++;
                p2++;
            }
            // record result
            int l = p2-p1;
            if(l > max_value) max_value = l;
            // release size k to k-1
            while(p1<p2 && check.size() >=k){
                char c = s[p1++];
                check[c]--;
                if(check[c] == 0) check.erase(c);
            }
        }
        return max_value;
    }
};