// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {

    ArrayList<Integer> arr;
    int size;
    public MedianFinder() {
        this.arr = new ArrayList<>();
        this.size = 0;
    }
    
    public void addNum(int num) {
        arr.add(num);
        size++;
        Collections.sort(arr);
    }
    
    public double findMedian() {
        int m1 = this.size / 2;
        if((this.size&1)== 1){
            return arr.get(m1);
        }else{
            int m2 = m1 - 1;
            return (arr.get(m1) + arr.get(m2)) / 2.0;
        }
    }
}

class MedianFinder {

    ArrayList<Integer> arr;
    int size;
    
    void insert(int num){
        int j = this.size - 1;
        while(j >= 0 && arr.get(j) > num){
            j--;
        }
        if(j + 1 < this.size)
            arr.add(j+1, num);
        else
            arr.add(num);
        this.size++;
    }
    
    public MedianFinder() {
        this.arr = new ArrayList<>();
        this.size = 0;
    }
    
    public void addNum(int num) {
        this.insert(num);
    }
    
    public double findMedian() {
        int m1 = this.size / 2;
        if((this.size&1)== 1){
            return arr.get(m1);
        }else{
            int m2 = m1 - 1;
            return (arr.get(m1) + arr.get(m2)) / 2.0;
        }
    }
}

class MedianFinder {
    
    PriorityQueue<Integer> leftList, rightList;
    int size;
    
    int getM1(){
        return rightList.peek();
    }
    
    int getM2(){
        return leftList.peek();
    }
    
    void rebalance(){
        int n1 = rightList.size();
        int n2 = leftList.size();
        if(n1 > n2){
            int el = rightList.poll();
            minHeap.add(el);
        }else{
            int el = minHeap.poll();
            rightList.add(el);
        }
    }
    
    void insert(int num){
        if(rightList.isEmpty() || num <= this.getM1()){
            rightList.add(num);
        }else{
            minHeap.add(num);
        }
        int n1 = rightList.size();
        int n2 = minHeap.size();
        if(n1 - n2 > 1 || n1 - n2 < 0){
            this.rebalance();
        }
        this.size++;
    }
    
    public MedianFinder() {
        this.minHeap = new PriorityQueue<>();
        this.rightList = new PriorityQueue<>(Collections.reverseOrder());
        this.size = 0;
    }
    
    public void addNum(int num) {
        this.insert(num);
    }
    
    public double findMedian() {
        if((this.size&1) == 1){
            return this.getM1();
        }else{
            return (this.getM1() + this.getM2()) / 2.0;
        }
    }
}

class MedianFinder {
    
    PriorityQueue<Integer> minHeap, maxHeap;
    int size;
    
    int getM1(){
        return maxHeap.peek();
    }
    
    int getM2(){
        return minHeap.peek();
    }
    
    void rebalance(){
        int n1 = maxHeap.size();
        int n2 = minHeap.size();
        if(n1 > n2){
            int el = maxHeap.poll();
            minHeap.add(el);
        }else{
            int el = minHeap.poll();
            maxHeap.add(el);
        }
    }
    
    void insert(int num){
        if(maxHeap.isEmpty() || num <= this.getM1()){
            maxHeap.add(num);
        }else{
            minHeap.add(num);
        }
        int n1 = maxHeap.size();
        int n2 = minHeap.size();
        if(n1 - n2 > 1 || n1 - n2 < 0){
            this.rebalance();
        }
        this.size++;
    }
    
    public MedianFinder() {
        this.minHeap = new PriorityQueue<>();
        this.maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        this.size = 0;
    }
    
    public void addNum(int num) {
        this.insert(num);
    }
    
    public double findMedian() {
        if((this.size&1) == 1){
            return this.getM1();
        }else{
            return (this.getM1() + this.getM2()) / 2.0;
        }
    }
}