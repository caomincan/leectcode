class Solution {
public:
    int calculate(string s) {
        stack<int> work;
        // push to stack when meet + or -, change sign for -
        // accumulate * or /
        int cur = 0;
        // init
        while(cur < s.size() && !isOp(s[cur])) cur++;
        int first_num = stoi(s.substr(0, cur));
       // cout << first_num;
        work.push(first_num);
        while(cur < s.size()){
            char op = s[cur++];
            int st = cur;
            while(cur< s.size() && !isOp(s[cur])) cur++;
            int next_num = stoi(s.substr(st, cur-st));
           // cout << " " << next_num;
            switch(op){
                case '+': work.push(next_num); break;
                case '-': work.push(-next_num); break;
                case '*': work.top() *= next_num; break;
                case '/': work.top() /= next_num; break;
            }
        }      
       // cout << endl;
        // final result
        int sum = 0;
        while(!work.empty()){
            sum += work.top();
            work.pop();
        }
        return sum;
    }
    
    bool isOp(char c){
        return c =='+' || c == '-' || c == '*' || c == '/';
    }
};