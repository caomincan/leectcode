class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <=1 ) return true;
        vector<int> dicts(26,0);
        for(int i=0;i<order.size();i++){
            dicts[(int)(order[i]-'a')] = i;
        }
        
        // verify part
        string& pre = words[0];
        for(int i= 1; i< words.size();i++){
            string& word = words[i];
            int cur = 0;
            while(cur < pre.size() 
                  && cur < word.size() 
                  && pre[cur] == word[cur]) 
            {
                cur++;
            }
            // next word is longer than previous and has same part of that word
            if(cur == word.size() && cur < pre.size()) return false;
            // compare different part
            if(cur < pre.size() && cur< word.size()){
                int x = (int)pre[cur]-'a';
                int y = (int)word[cur]-'a';
                if(dicts[x] > dicts[y]) return false;
            }
            pre = word;
        }
        return true;
    }
};