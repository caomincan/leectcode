class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = (int)num1.size()-1;
        int p2 = (int)num2.size()-1;
        
        stringstream buff;
        int carry = 0;
        while(p1>=0 || p2>=0){
            int a = p1>=0? (num1[p1--] - '0'):0;
            int b = p2>=0? (num2[p2--] - '0'):0;
            int sum = a+b+carry;
            buff << (char)('0'+ sum%10);
            carry = sum/10;
        }
        if(carry) buff << '1';
        string ans = buff.str();
        return string(ans.rbegin(), ans.rend());
    }
};