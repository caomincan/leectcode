class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
		// using long long because -n cannot fit int 
		// when int is INT_MIN
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        return fastPow(x, N);
    }
    
    double fastPow(double x, long long n){
        if(x == 1) return 1;
        if(n == 0) return 1;
        else if (n == 1) return x;
        else if(n == 2) return x*x;

        return n%2 == 1 ? myPow(myPow(x,n/2),2)*x : myPow(myPow(x,n/2),2);
    }
};