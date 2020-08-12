class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> tmp;
        for(int i=(int)deck.size()-1;i>=0;i--){
            if(tmp.empty()){
                tmp.push_back(deck[i]);
            }else{
                int back = tmp.back();
                tmp.pop_back();
                tmp.push_front(back);
                tmp.push_front(deck[i]);
            }
        }
        return vector<int>(tmp.begin(),tmp.end());
    }
};