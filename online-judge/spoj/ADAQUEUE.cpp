#include <iostream>
#include <deque>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast
    int n; cin >> n;
    string opr;
    int x;
    bool ir = false;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        cin >> opr;
        if(opr == "push_back"){
            cin >> x;
            if(ir){
                dq.push_front(x);
            }else{
                dq.push_back(x);
            }
        }else if(opr == "toFront"){
            cin >> x;
            if(ir){
                dq.push_back(x);
            }else{
                dq.push_front(x);
            }
        }else if(opr == "reverse"){
            ir = !ir;
        }else if(opr == "front"){
            if(dq.empty()){
                cout << "No job for Ada?" << "\n";
            }else{
                if(ir){
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }else{
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
            }
        }else if(opr == "back"){
            if(dq.empty()){
                cout << "No job for Ada?" << "\n";
            }else{
                if(ir){
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }else{
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
            }
        }
    }
    return 0;
}