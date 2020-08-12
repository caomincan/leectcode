class Solution {
public:
    static constexpr int mod = 1000000007;
    int numPrime(int n){
        int ans = 0;
        int isPrime = true;
        for(int i=2;i<=n;i++){
            // test if  i is Prime
            for(int j=2;j*j <= i; j++){
                if(i%j == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                ans++;
            }else{
                isPrime = true;
            }
        }
        return ans;
    }
    
    long long factor(int n){
        long long ans = 1;
        while(n>1){
            ans =  (ans*n )%mod;
            n--;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        int nP = numPrime(n);
        long long ans = factor(nP)%mod * factor(n-nP)%mod;
        return ans%mod;
    }
};