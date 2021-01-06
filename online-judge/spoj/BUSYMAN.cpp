#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef pair<int,int> pii;


bool cmp(const pii &a, const pii &b){
    return a.second < b.second;
}

int solve(vector<pii> &ar, int n){
    int cnt = 1;
    pii curr = ar[0]; // select the activity with will end first
    for(int i = 1; i < n; i++){
        if(ar[i].first >= curr.second){ // if activity start time is >= curr activity end then select it
            curr = ar[i];
            ++cnt;
        }
    }
    return cnt;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pii> act(n);
        int a,b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            act[i] = make_pair(a,b);
        }
        sort(act.begin(), act.end(), cmp); // sort activity wrt to end time
        cout << solve(act, n) << "\n";
    }
    return 0;
}