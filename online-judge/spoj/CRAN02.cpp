#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

// ll solve(vector<int> &ar, int n){
//     int res = 0;
//     for(int i = 0; i < n; i++){ // start
//         int cs = 0;
//         for(int j = i; j < n; j++){
//             cs += ar[j];
//             if(cs == 0) res++;
//         }
//     }
//     return res;
// }

ll solve(vector<int> &ar, int n){
    vector<int> pref(n);
    pref[0] = ar[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + ar[i];
    }
    unordered_map<int,int> hm;
    ll res = 0;
    for(int i = 0; i < n; i++){
        if(pref[i] == 0){
            res++;
        }
        if(hm.find(pref[i]) != hm.end()){
            res += hm[pref[i]];
        }
        hm[pref[i]] += 1;
    }
    return res;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i=0;i<n;i++)
            cin >> ar[i];
        cout << solve(ar, n) << "\n";
    }
    return 0;
}