class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> tmp;
        while(num> 0){          
            string word = numberToWords_less_1k(num%1000);
            tmp.push_back(move(word));
            num /= 1000;
        }
        stringstream buff;
        for(int i= (int)tmp.size()-1;i>=0;i--){
            string& cur = tmp[i];
            if(i < (int)tmp.size()-1 && !buff.str().empty() && !tmp[i].empty()){
                buff << " ";
            }
            if(!cur.empty()){
                buff<< cur << ( i > 0 ? " " + tmb(i) : "");
            }
        }
        return buff.str();
    }
    
    string tmb(int count){
        switch(count){
            case 3: return "Billion";
            case 2: return "Million";
            case 1: return "Thousand";
            default: return "";
        }
        return "";
    }
    
    string numberToWords_less_1k(int num){
        stringstream buff;
        // hundred
        int h = num/100;
        if( h> 0){
            buff << numberToWords_less_10(h) << " Hundred";
        }
        num %= 100;
        if(h>0 && num != 0) buff << " ";
        if(num >= 20){
            buff<< numberToWorks_large_20(num/10);
            if(num%10 != 0) buff << " ";
            buff<< numberToWords_less_10(num%10);
        }else if(num >= 10){
            buff << numberToWords_special(num);
        }else {
            buff << numberToWords_less_10(num);
        }
        return buff.str();
    }
    
    string numberToWorks_large_20(int num){
        switch(num){
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
            default: return "";
        }
        return "";
    }
    string numberToWords_less_10(int num){
        switch(num){
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            default: return "";
        }
        return "";
    }
    
    string numberToWords_special(int num){
        switch(num){
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            default: return "";
        }
        return "";
    }
};