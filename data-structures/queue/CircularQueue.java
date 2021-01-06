import java.util.*;
public class CircularQueue {
    int cnt;
    int head;
    int tail;
    int[] arr;
    int size;
    public MyCircularQueue(int k) {
        this.size = k;
        this.arr = new int[this.size];
        this.head = 0;
        this.tail = -1;
        this.cnt = 0;
    }
    
    public boolean enQueue(int value) {
        if(isFull()){
            return false;
        }
        tail++;
        if(this.tail >= this.size){
            this.tail = this.tail % this.size;
        }
        this.arr[this.tail] = value;
        this.cnt++;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty()){
            return false;
        }
        this.head++;
        if(this.head >= this.size){
            this.head = this.head % this.size;
        }
        this.cnt--;
        return true;
    }
    
    public int Front() {
        if(isEmpty()){
            return -1;
        }
        return this.arr[this.head];
    }
    
    public int Rear() {
        if(isEmpty()){
            return -1;
        }
        return this.arr[this.tail];
    }
    
    public boolean isEmpty() {
        if(this.tail == -1){
            return true;
        }
        return this.cnt == 0;
    }
    
    public boolean isFull() {
        if(this.tail == -1){
            return false;
        }
        return this.cnt == this.size;
    }
}