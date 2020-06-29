class Solution {
public:
    struct Word{
        string word;
        int freq;
        Word(string& w, int aFreq):
            word(w), freq(aFreq)
        {
            
        }
    };
    
    struct Comp{
      bool operator()(const Word* A, const Word* B) const{
        if(A->freq != B->freq){
                return A->freq > B->freq;
            }else{
                const string& a = A->word;
                const string& b = B->word;
                // string for alphabetical order
                const int n = a.size() < b.size() ? (int) a.size() : (int) b.size();
                const string& s = a.size() < b.size() ? a : b;
                const string& l = a.size() >= b.size() ? a : b;
                if(l.substr(0, n) == s) return a.size() < b.size();
                else {
                    for(int i=0;i<n;i++){
                        if(a[i] == b[i]) continue;
                        else return a[i]<b[i];
                    }
                    return a[n-1] < b[n-1];
                }
            }    
      }  
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(k == 0) return {};
        vector<string> ans;
        set<Word*, Comp> sorting;
        unordered_map<string, Word*> data;
        for(auto& w : words){
            auto it = data.find(w);
            if(it == data.end()){
                data[w] = new Word(w,1);
                sorting.insert(data[w]);
            }else{                
                Word* old = it->second;
                int freq = old->freq+1;
                sorting.erase(old);
                data[w] = new Word(w, freq);
                sorting.insert(data[w]);
                delete old;
            }
        }
        // get first k
        int count = 0;
        for(auto w: sorting){
            if(count >= k) break;
            ans.push_back(w->word);
            count++;
        }
        return ans;
    }
};