class circular_queue {
    int size;
    int head;
    int tail;
    int count;
    int *arr;

public:
    circular_queue(int k){
        this->size = k;
        head = 0;
        tail = -1;
        count = 0;
        arr = new int[size];
    }

    int Front(){
        if(isEmpty()){
            return -1;
        }
        return arr[head];
    }
    int Rear(){
        if(isEmpty()){
            return -1;
        }
        return arr[tail];
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == size;
    }
    bool enQueue(int value){
        if(isFull()){
            return false;
        }
        tail++;
        if(tail >= size){
            tail = 0;
        }
        arr[tail] = value;
        count++;
        return true;
    }
    bool deQueue(){
        if(isEmpty()){
            return false;
        }
        head++;
        if(head >= size){
            head = 0;
        }
        count--;
        return false;
    }
}