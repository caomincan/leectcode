class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > ans;
        int p1 = 0;
        int p2 = 0;
        while(p1 < A.size() && p2 < B.size()){
            auto& a = A[p1];
            auto& b = B[p2];
            switch(compare(a,b)){
                case -1: p1++; break;
                case  1: p2++; break;
                default:
                    auto inter = intersection(a, b);
                    if(a[1] <= inter[1]) p1++;
                    else p2++;
                    ans.push_back(move(inter));
            }                                                        
        }
        return ans;
    }
    
    // compare two interval
    // -1 if a is at b left
    // 1 if a is at b right
    // 0 if a and b has intersection
    int compare(vector<int>& a, vector<int>& b){
        if(a[1] < b[0]) return -1;
        if(a[0] > b[1]) return 1;
        return 0;
    }
    
    vector<int> intersection(vector<int>& a, vector<int>& b){
        vector<int> ans(2,0);
        ans[0] = max(a[0],b[0]);
        ans[1] = min(a[1],b[1]);
        return ans;
    }
};