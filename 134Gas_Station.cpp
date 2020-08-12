class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty()) return -1;
        const int n = (int)gas.size();
        vector<int> net(n, 0);
        int sum = 0;
        for(int i=0;i<n;i++){
            net[i] = gas[i]-cost[i];
            sum += net[i];
        }
        // not possible
        if(sum < 0){
            return -1;
        }
        int cur = 0;
        int subsum = 0;
        for(int i=0;i<n;i++){
            subsum += net[i];
            if(subsum < 0){
                cur = i+1<n? i+1 : i;
                subsum = 0;
            }
        }
        return cur;
    }
};