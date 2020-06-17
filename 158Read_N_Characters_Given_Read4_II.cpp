/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
	 //Runtime: 4 ms, faster than 15.03% of C++ online submissions for Read N Characters Given Read4 II 
    // not good enough
    int read(char *buf, int n) {
        // has enough tmp buff
        int m = static_cast<int>(buff.size());
        if(n<= m){
            for(int i = 0;i<n;i++){
                buf[i] = buff[i];
            }
            // clear the rest
            buff = buff.substr(n);
            return n;
        } else{
            // not enough
            char* tmp = new char[4];
            stringstream words;
            words<< buff;
            int count = m;
            do{
                int res = read4(tmp);
                if(res == 0) break;
                for(int i=0;i<res;i++){
                    words << tmp[i];
                }
                count += res;
            } while(count<n);
            delete[] tmp;
            string str = words.str();
            for(int i=0;i< min(count,n);i++){
                buf[i] = str[i];
            }
            if(count > n){
                buff = str.substr(n);
            } else{
                buff = str.substr(count);
            }
            return min(count, n);
        }
        
    }
    
    string buff;
};