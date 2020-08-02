class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int num_line = 0;
        constexpr int W = 100;
        int sum = 0;
        for(auto c: S){
            int width = widths[(int)(c-'a')];
            if(width+sum > W){
                sum = width;
                num_line++;
            }else{
                sum += width;
            }
        }
        if(sum > 0){
            num_line++;
        }
        return {num_line, sum};
    }
};