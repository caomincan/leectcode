class Solution {
public:
    string addBinary(string a, string b) {
        stringstream buff;
        int p = 0;
        const int m = static_cast<int>(a.size());
        const int n = static_cast<int>(b.size());
        int carry = 0;
        while(p < m || p< n){
            int sum = 0;
            if(m-p <= 0){
                sum = b[n-p-1]-'0';
            } else if (n-p<= 0){
                sum = a[m-p-1]-'0';
            }else{
                sum = (b[n-p-1]-'0')+(a[m-p-1]-'0');
            }
            sum += carry;
            buff << (sum%2 == 1 ? "1": "0");
            carry = sum/2;
            p++;
        }
        if(carry != 0) { buff << "1";}
        string ans = buff.str();
        return string(ans.rbegin(),ans.rend());
    }
};