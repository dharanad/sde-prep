#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

bool good(vector<ll> &ar, int n, ll m, ll h){
    ll w = 0;
    for(ll x : ar){
        if(x > h){
            w += abs(x - h);
        }
    }
    return w >= m;
}

int main(){
    fast
    int n; cin >> n;
    ll m; cin >> m;
    vector<ll> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    ll lo = 0;
    ll hi = *max_element(ar.begin(), ar.end());
    while(lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        if(good(ar, n, m, mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    return 0;
}