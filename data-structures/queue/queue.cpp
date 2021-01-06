#include <vector>

class queue {
    vector<int> q;
    int head;
    public:
        queue(){
            head = 0;
        }
        bool isEmpty(){
            return head >= q.size();
        }
        int front(){
            return q[head];
        }
        bool pop(){
            if(isEmpty()){
                return false;
            }
            head++;
            return true;
        }
        bool push(int x){
            q.push_back(x);
            return true;
        }
};