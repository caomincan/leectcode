class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        int p = 0;
        while(p < paragraph.size()){
            int st = p;
            while(p<paragraph.size() && isChar(paragraph[p])) p++;
            string word(p-st, 0);
            for(int i=0; i< p-st;i++){
                word[i] = tolower(paragraph[st+i]);
            }
            if(ban.find(word) == ban.end()){
                count[word]++;
            }
            while(p<paragraph.size() && !isChar(paragraph[p])) p++;
        }
        int max_count = -1;
        string ans;
        for(auto& p:count){
            if(p.second > max_count){
                max_count = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
    bool isChar(char c){
        return (c>='a' && c<='z')
            ||(c >= 'A' && c<= 'Z');
    }
};