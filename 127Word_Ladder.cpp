class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Since all words are of same length.
        int L = (int)beginWord.size();

        // Dictionary to hold combination of words that can be formed,
        // from any given word. By changing one letter at a time.
        unordered_map<string, vector<string>> allComboDict;

        for(auto& word: wordList){
            for (int i = 0; i < L; i++) {
                // Key is the generic word
                // Value is a list of words which have the same intermediate generic word.
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1);
                auto& transformations = allComboDict[newWord];
                transformations.push_back(word);
            }
        }
        
        // Queue for BFS
        queue<string> Q;
        Q.push(beginWord);
        
        // Visited to make sure we don't repeat processing same word.
        unordered_map<string, bool> visited;
        visited[beginWord]= true;

        int level = 1;
        while (!Q.empty()) {
            int count = Q.size();
            while(count> 0){
                string word = Q.front();
                Q.pop();
                count--;
                for (int i = 0; i < L; i++) {

                    // Intermediate words for current word
                    string newWord = word.substr(0, i) + '*' + word.substr(i + 1);

                    // Next states are all the words which share the same intermediate state.
                    for (auto adjacentWord : allComboDict[newWord]) {
                        // If at any point if we find what we are looking for
                        // i.e. the end word - we can return with the answer.
                        if (adjacentWord == endWord) {
                            return level + 1;
                        }
                        // Otherwise, add it to the BFS Queue. Also mark it visited
                        if (visited.find(adjacentWord) == visited.end()) {
                            visited[adjacentWord]= true;
                            Q.push(adjacentWord);
                        }
                    }
                }
            }
            level++;
        }
            
        return 0;
    }
    

};