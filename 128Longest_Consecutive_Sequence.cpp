class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> leaders;
        unordered_map<int,int> ranks;
        // union all
        for(auto n: nums){
            if(leaders.find(n) != leaders.end()) continue; // already exsit
            // init
            leaders[n] = n;
            ranks[n] = 0;
            if(leaders.find(n-1) != leaders.end()){
                union_two(leaders, ranks, n-1, n);
            }
            if(leaders.find(n+1) != leaders.end()){
                union_two(leaders, ranks, n, n+1);
            }
        }
        // count;
        unordered_map<int, int> counter;
        int ans = 0;
        for(auto& p: leaders){
            int l = find_leader(leaders, p.first);
            counter[l]++;
            if(counter[l] > ans){
                ans = counter[l];
            }
        }
        return ans;
    }
    
    int find_leader(unordered_map<int,int>& leaders, const int k){
        int l = leaders[k];
        if(l == k) return l;
        // path compression
        leaders[k] = find_leader(leaders, l);
        return leaders[k];
    }
    
    void union_two(unordered_map<int,int>& leaders, unordered_map<int,int>& ranks, const int a, const int b){
        int la = find_leader(leaders, a);
        int lb = find_leader(leaders, b);
        if(la == lb) return; // same
        int ra = ranks[la];
        int rb = ranks[lb];
        if(ra > rb){
            // change lb to la
            leaders[lb] = la;
        }else if(ra < rb){
            leaders[la] = lb;
        }else{
            // rank same
            leaders[lb] = la;
            ranks[la]++;
        }
    }
};

/*  Intelligent sequence building
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(auto n: nums){
            num_set.insert(n);
        }
        
        int ans = 0;
        for(auto n: num_set){
            if(num_set.find(n-1) != num_set.end()) {
                continue;
            }
            int count = 1;
            while(num_set.find(n+1) != num_set.end()){
                count++;
                n++;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
*/