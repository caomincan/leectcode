class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> count;
        if(!isAbleGenerate(s, count)) return {};
        string pool;
        string middle("");
        for(auto& p: count){
            int num = p.second;
            if(p.second %2 == 1) {
                middle = string(1,p.first);
                num--;
            }
            num /=2;
            pool.insert(pool.end(), num,p.first);
        }
        // generating
        unordered_set<string> half;
        vector<string> ans;
        backtracking(pool, half);
        for(auto& str: half){
            ans.push_back (str + middle + string(str.rbegin(), str.rend()));
        }
        return ans;
    }
    
    void swap(string& s, int i, int j){
        auto tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    void backtracking(string& pool, unordered_set<string>& half, int cur = 0){
        if(cur == pool.size()){
            half.insert(pool);
            return;
        }
        for(int i= cur;i<pool.size();i++){
            if( i== cur || pool[i] != pool[cur]){
                swap(pool, cur, i);
                backtracking(pool, half, cur+1);
                swap(pool, cur, i);
            }
        }
    }
    
    bool isAbleGenerate(string& s, unordered_map<char,int>& count){
        int numOdd = 0;
        for(auto& c : s){
            count[c]++;
            if(count[c]%2 == 1){
                numOdd++;
            }else{
                numOdd--;
            }
        }
        return numOdd <=1;
    }
};