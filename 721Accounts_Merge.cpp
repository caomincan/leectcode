class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        if(accounts.empty()) return ans;
        
        const int n = (int)accounts.size();
        unordered_map<string,int> emails; // only record leader index
        // union find struct
        vector<int> leaders(n,0);
        vector<int> ranks(n, 0);
        for(int i=0;i<n;i++) leaders[i] = i;
        // start union
        for(int i=0;i<n;i++){
            auto& account = accounts[i];
            for(int j=1;j<account.size();j++){
                if(emails.find(account[j]) == emails.end()){
                    emails[account[j]] = i;
                }else{
                    int old_leader = emails[account[j]];
                    emails[account[j]] = union_(leaders, ranks, i, old_leader);
                }
            }
        }
        // create ans
        unordered_map<int, int> map; // leader to ans map
        vector<set<string>> sorted_emails;
        for(int i=0;i<n;i++){
            auto& account = accounts[i];
            int leader = find_leader(leaders, i);
            if(map.find(leader) == map.end()){
                map[leader] = (int)sorted_emails.size();
                sorted_emails.push_back(set<string>());
                ans.push_back({account[0]});
            }
            auto& list = sorted_emails[map[leader]];
            for(int j=1;j<account.size();j++){
                auto& email = account[j];
                list.insert(email);
            }
           
        }
        
        for(int i=0;i<ans.size();i++){
            auto& list = ans[i];
            list.insert(list.begin()+1, sorted_emails[i].begin(), sorted_emails[i].end());
        }
        
        return ans;
    }
    
    int find_leader(vector<int>& leaders, int cur){
        if(cur == leaders[cur]) return cur;
        leaders[cur] = find_leader(leaders, leaders[cur]);// path compression
        return leaders[cur];
    }
    
    int union_(vector<int>& leaders, vector<int>& ranks, int i, int j){
        int leader_i = find_leader(leaders, i);
        int leader_j = find_leader(leaders, j);
        if(leader_i == leader_j) return leader_i;
        int ri = ranks[leader_i];
        int rj = ranks[leader_j];
        if(ri < rj){
            leaders[leader_i] = leader_j;
            return leader_j;
        } else if( ri > rj){
            leaders[leader_j] = leader_i;
            return leader_i;
        } else{
            leaders[leader_j] = leader_i;
            ranks[leader_i]++;
            return leader_i;
        }
    }
};