class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> asc;
    priority_queue<int, vector<int>, greater<int>> desc;
    int llen,rlen;

    MedianFinder() {
        llen = 0;
        rlen = 0;
    }
    
    void addNum(int num) {
        //stream is empty
        if(llen == 0){
            llen++;
            asc.push(num);
        }
        //at least 1 element
        else{
            //need to add at right queue
            if(llen > rlen){
                int leftTopNum = asc.top();
                asc.pop();
                int minVal = min(leftTopNum, num);
                int maxVal = max(leftTopNum, num);
                asc.push(minVal);
                desc.push(maxVal);
                rlen++;
            }
            //need to add to left queue
            else{
                if(num > desc.top()){
                    int leftVal = desc.top();
                    desc.pop();
                    asc.push(leftVal);
                    desc.push(num);
                }
                else {
                    asc.push(num);
                }
                llen++;
            }
        }
    }
    
    double findMedian() {
        double median = 0.0;
        if(llen == 0) return median;
        
        if(llen > rlen) median = asc.top();
        else median = ((double)asc.top() + (double)desc.top())/2;
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */