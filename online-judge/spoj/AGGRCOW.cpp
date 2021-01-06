#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool good(vector<int> &ar, int n, int md, int c){
    int cnt = 1;
    for(int i = 0, pos; i < n; i = pos){
        int curr = ar[i];
        int next = curr + md;
        pos = lower_bound(ar.begin(), ar.end(), next) - ar.begin();
        if(pos < n){
            cnt++;
            if(cnt >= c){
                return true;
            }
        }
    }
    return false;
}

int solve(vector<int> &ar, int n, int c){
    int hi = ar[n-1] - ar[0];
    int lo = ar[1] - ar[0];
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(good(ar, n, mid, c)){
            lo = mid;
        }else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> st(n);
        for(int i = 0; i < n; i++)
            cin >> st[i];
        sort(st.begin(), st.end());
        cout << solve(st, n, c) << "\n";
    }
    return 0;
}