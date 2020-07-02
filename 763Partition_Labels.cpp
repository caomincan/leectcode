class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        for(int i=0;i< S.size();i++){
            last[S[i]-'a'] = i;
        }
        
        vector<int> ans;
        int j = 0 , anchor = 0;
        for(int i=0;i< S.size();i++){
            j = max(j, last[S[i]-'a']);
            if( i == j){
                ans.push_back(i-anchor+1);
                anchor = i+1;
            }
        }
        return ans;
    }
};