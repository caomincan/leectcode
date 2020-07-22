class Solution {
public:
    int fib(int N) {
        if(N== 0) return 0;
        if(N <= 2) return 1;
        int pn_2 = 1, pn_1 = 1;
        int ans = 0;
        for(int i=2;i< N;i++){
            ans = pn_2 + pn_1;
            pn_2 = pn_1;
            pn_1 = ans;
        }
        return ans;
    }
};