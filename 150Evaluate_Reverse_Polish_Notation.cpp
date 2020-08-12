class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int sum = 0;
        stack<pair<string, string>> ops;
        for(int i = (int)tokens.size()-1;i>=0;i--){
            if(isNum(tokens[i])){
                sum = stoi(tokens[i]);
                // ops is not empty
                while(!ops.empty() && !ops.top().second.empty()){
                    auto& op = ops.top();
                    switch(op.first[0]){
                        case '+': sum +=stoi(op.second); break;
                        case '-': sum -=stoi(op.second); break;
                        case '*': sum *=stoi(op.second); break;
                        case '/': sum /=stoi(op.second); break;
                    }
                    ops.pop();
                }
                if(!ops.empty() && ops.top().second.empty()){
                    ops.top().second = to_string(sum);
                }
            }else{
                if(isNum(tokens[i-1])){
                    ops.push(make_pair(tokens[i], tokens[i-1]));
                    i--;
                }else{
                    ops.push(make_pair(tokens[i], "")); // second is empty
                }
            }
        }
        return sum;
    }
    
    bool isNum(string& s){
        return !(s == "+" || s=="-" || s=="*" || s== "/");
    }
};