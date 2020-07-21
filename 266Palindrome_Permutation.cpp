class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> count;
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