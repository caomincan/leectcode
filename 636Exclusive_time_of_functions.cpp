class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n,0);
        stack<pair<int,int>> works; // id, start time_stamp
        
        for(auto& log: logs){
            // process log
            int p = 0;
            while(p<log.size() && log[p] != ':') p++;
            int id = stoi(log.substr(0,p++));
            int st = p;
            while(p<log.size() && log[p] != ':') p++;
            string op = log.substr(st, p-st);
            int timestamp = stoi(log.substr(p+1));
            if(op == "start"){
                if(!works.empty()){
                    auto& job = works.top();
                    times[job.first] += timestamp-job.second;
                    
                }
                works.push(make_pair(id, timestamp)); // insert to queue               
            }else if(op == "end"){
               // assert(!works.empty());
                auto& job = works.top();
                //assert(job.first == id);
                times[job.first] += timestamp-job.second+1;
                works.pop();
                if(!works.empty()){
                    works.top().second = timestamp+1;
                }
            }
        }
            
        return times;
    }
};