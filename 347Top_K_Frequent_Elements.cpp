class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count frequent
        unordered_map<int,int> f;
        for(auto n: nums){
            f[n]++;
        }
        vector<pair<int,int>> heap;
        auto comp = [](const pair<int,int>& a, const pair<int,int>& b){
          return a.second > b.second;  
        };
        for(auto p: f){
            if(heap.size() < k){
                push(heap, p, comp);
            }else{
                // larger than k
                auto& minP = heap.front();
                if(p.second > minP.second){
                    pop(heap, comp);
                    push(heap, p, comp);
                }
            }
        }
        // get answer
        vector<int> ans;
        while(!heap.empty()){
            auto& v = heap.front();
            ans.push_back(v.first);
            pop(heap, comp);
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
    
    // min heap
    template<class T>
    void push(vector<pair<int,int>>& heap, pair<int,int> k, T comp){
        heap.push_back(k);
        push_heap(heap.begin(), heap.end(), comp);
    }
    
    template<class T>
    void pop(vector<pair<int,int>>& heap, T comp){
        pop_heap(heap.begin(), heap.end(), comp);
        heap.pop_back();
    }
};