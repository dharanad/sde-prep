#include <iostream>
#include <stack>
#include <utility>
#include <climits>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast
    stack<pair<int,int> > min_stk;
    int n; cin >> n;
    string opr;
    int x, mn = INT_MAX;
    for(int i = 0; i < n; i++){
        cin >> opr;
        if(opr == "PUSH"){
            cin >> x;
            if(min_stk.empty()){
                min_stk.push(make_pair(x,x));
            }else{
                min_stk.push(make_pair(x, min(x, min_stk.top().second)));
            }
        }else{
            if(min_stk.empty()){
                cout << "EMPTY" << '\n';
            }else if(opr == "POP"){
                min_stk.pop();
            }else if(opr == "MIN"){
                cout << min_stk.top().second << '\n';
            }
        }
    }
    return 0;
}