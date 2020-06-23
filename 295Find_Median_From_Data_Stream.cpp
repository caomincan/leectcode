class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) {
            push(maxHeap, num, true);
        } else{
            int x = maxHeap.front();
            if(num <= x){
                push(maxHeap, num, true);
            } else {
                push(minHeap, num, false);
            }
        }
        size++;
        // keep balance

        if(size%2 == 0){
           while(maxHeap.size() != minHeap.size())
           {
               if(maxHeap.size() > minHeap.size()){
                   int tmp = maxHeap.front();
                   pop(maxHeap, true);
                   push(minHeap, tmp, false);
               } else{
                   int tmp = minHeap.front();
                   pop(minHeap, false);
                   push(maxHeap, tmp, true);
               }
           } 
        }else{
            while( (int)maxHeap.size()- (int)minHeap.size() != 1)
            {
               if((int)maxHeap.size()- (int)minHeap.size() >1 ){
                   int tmp = maxHeap.front();
                   pop(maxHeap, true);
                   push(minHeap, tmp, false);
               } else{
                   int tmp = minHeap.front();
                   pop(minHeap, false);
                   push(maxHeap, tmp, true);
               }
            } 
        }
      
    }
    
    double findMedian() {
        double x = (double)maxHeap.front();
        if(size %2 == 1){
            // odd
            return x;
        }else{
            double ans = (x+ (double)minHeap.front())/2.0; 
            return ans;
        }
    }
    
    void push(vector<int>& heap, int x, bool isMaxHeap){
        heap.push_back(x);
        if(isMaxHeap){
             push_heap(heap.begin(), heap.end(), less<int>());
        }else{
             push_heap(heap.begin(), heap.end(), greater<int>());
        }
       
    }
    
    void pop(vector<int>& heap, bool isMaxHeap){
        if(isMaxHeap){
            pop_heap(heap.begin(),heap.end(), less<int>());
        }else{
            pop_heap(heap.begin(),heap.end(), greater<int>());
        }     
        heap.pop_back();
    }
    
    vector<int> maxHeap; // left
    vector<int> minHeap; // right
    int size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */