class Solution {
public:
    struct Task{
        char key;
        int count;
        Task(char k): 
            key(k), count(1)
        {}
    };
    
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,Task*> my_tasks;
        vector<Task*> pool;
        
        // prepare
        for(auto c: tasks){
            if(my_tasks.find(c) == my_tasks.end()){
                Task* t = new Task(c);
                pool.push_back(t);
                my_tasks[c] = t;
            }else{
                my_tasks[c]->count++;
            }
        }
        vector<string> ans;
        
        auto Comp = [](const Task* t1, const Task* t2) -> bool{
            return t1->count > t2->count;
        };
        
        //sorting once
        sort(pool.begin(), pool.end(), Comp);
        int f_max = pool[0]->count;
        int idle_time = (f_max-1)*n;
        
        for(int i=1;i<pool.size() && idle_time > 0;i++){
            idle_time -= min(f_max-1, pool[i]->count);
        }
        
        idle_time = max(0, idle_time);
        return idle_time+tasks.size();
#if 0
        for(auto& s: ans){
            cout << s <<",";
        }
        cout << endl;
#endif
    }
};