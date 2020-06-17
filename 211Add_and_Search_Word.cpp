class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        const int n = static_cast<int>(word.size());
        auto it = data.find(n);
        if(it != data.end()){
            it->second.insert(word);
        }else{
            set<string> tmp;
            tmp.insert(word);
            data.insert(make_pair(n, tmp));
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        const int n = static_cast<int>(word.size());
        auto it = data.find(n);
        // no match size
        if(it == data.end()) {return false;}
        set<string>& lists = it->second;
        auto str = lists.find(word);
        // has exactly match
        if(str != lists.end()) { return true;}
        // contains dot 
        vector<bool> record(lists.size(), true);
        for(int i=0;i<n;i++){
            if(word[i] == '.') continue; // dot just continue
            int count = 0;
            for(auto& w: lists){
                if(record[count]){
                    record[count] = (w[i] == word[i]);
                }
                count++;
            }
        }
        bool isAnyTrue = false;
        for(auto b: record) { isAnyTrue |= b;}
        return isAnyTrue;
    }
    
    unordered_map<int, set<string>> data; //set ensure order is same
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */