class Solution {
public:
    int maximumSwap(int num) {
        vector<int> rMaxs;
        vector<int> myNum;
        
        int x = num;
        int max_value = 0;
        while(x > 0){
            int digit = x%10;
            max_value = max(digit, max_value);
            myNum.push_back(digit);
            rMaxs.push_back(max_value);
            x /= 10;
        }
        
        int i = (int)myNum.size()-1;
        for( ;i>=0;i--){
            if(rMaxs[i] > myNum[i]) break;
        }
        if(i < 0) return num; // no swap happen
        
        int j = 0;
        for(; j<i;j++){
            if(myNum[j] == rMaxs[i]) break;
        }
        
        if(i!=j) swap(myNum, i, j);
        int ans = 0;
        for(int k=(int)myNum.size()-1;k>=0;k--){
            ans *=10;
            ans += myNum[k];
        }
        return ans;
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};