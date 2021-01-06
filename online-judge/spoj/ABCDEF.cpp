#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*
lhs = a * b + c
rhs = (f + e) * d
*/

int main(){
    fast
    int n; cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    vector<int> l, r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int lhs = ar[i] * ar[j] + ar[k];
                l.push_back(lhs);
                if(ar[k] != 0){
                    int rhs = (ar[i] + ar[j]) * ar[k];
                    r.push_back(rhs);
                }
            }
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int res = 0;
    for(int x : l){
        int lo = lower_bound(r.begin(), r.end(), x) - r.begin();
        int hi = upper_bound(r.begin(), r.end(), x) - r.begin();
        int cnt = hi - lo;
        res += cnt;
    }
    cout << res << "\n";
    return 0;
}