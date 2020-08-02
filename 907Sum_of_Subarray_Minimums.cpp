class Solution {
public:
    int m = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
        if(A.empty()) return 0;
        const int num = A.size();
        
      
        vector<int> left(num, -1);
        stack<int> s;
        for(int i =0;i < num;i++){
            while(!s.empty() && A[i] <= A[s.top()]){
                s.pop();
            }
            left[i] = s.empty()? -1 : s.top();
            s.push(i);
        }
        
        s = {};
        vector<int> right(num, -1);
        for(int i= num-1 ;i >=0;i--){
            while(!s.empty() && A[i] < A[s.top()]){
                s.pop();
            }
            right[i] = s.empty()? num : s.top();
            s.push(i);
        }
        
        // calculate
        long long sum = 0;
        for(int i=0;i<num;i++){
            sum += (i-left[i])*(right[i]-i)%m *A[i]%m;
        }
        return sum%m;
    }
};