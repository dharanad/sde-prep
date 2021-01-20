#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <queue>
#include <vector>
void add(deque<int> &q, int x){
    while(!q.empty() && q.back() < x){
        q.pop_back();
    }
    q.push_back(x);
}
int main(){
    fast
    int n; cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    int k; cin >> k;
    deque<int> dq;
    for(int i = 0; i < k; i++){
        add(dq, ar[i]);
    }
    cout << dq.front() << " ";
    for(int i = k; i < n; i++){
        if(dq.front() == ar[i - k]){
            dq.pop_front();
        }
        add(dq, ar[i]);
        cout << dq.front() << " ";
    }
    return 0;
}