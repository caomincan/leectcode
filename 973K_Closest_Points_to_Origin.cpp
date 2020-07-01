class Solution {
public:
    struct Point{
      Point(vector<int>& p, double d) :
        pos(p), dist(d) {}
      vector<int> pos;
      double dist;  
    };
    
    struct Comp{
      bool operator()(const Point& p1, const Point& p2) const {
          return p1.dist < p2.dist;
      }  
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<Point> list; // max heap
        
        for(auto& point: points){
            // no need sqrt to save time
            double d = point[0]*point[0] + point[1]*point[1];
            if(list.size() < K) {
                push(list, point, d);
            }else{
                auto& ref_p = list.front();
                if(d < ref_p.dist){
                    if(list.size() >= K){
                        //remove maximum value
                        pop(list);
                    }
                    push(list, point, d);
                }
            }
        }
        
        vector<vector<int> > ans;
        for(auto& p : list){
            ans.push_back(move(p.pos));
        }
        return ans;
    }
    
    void push(vector<Point>& list, vector<int>& p, double d){
        list.push_back(Point(p,d));
        push_heap(list.begin(),list.end(), Comp());
    }
    
    void pop(vector<Point>& list){
        pop_heap(list.begin(), list.end(), Comp());
        list.pop_back();
    }
};