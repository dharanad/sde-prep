#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

bool iss(ll x, int b){
    return (x & (1LL << b)) > 0;
}

vector<ll> get_ss(vector<ll> &ar){
    vector<ll> res;
    int n = ar.size();
    ll i = 0;
    ll size = (1LL << n);
    for(i; i < size; i++){
        ll sum = 0;
        for(int b = 0; b < n; b++){
            if(iss(i, b)){
                sum += ar[b];
            }
        }
        res.push_back(sum);
    }
    return res;
}

int main(){
    fast
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> ar(n);
    for(ll i = 0; i < n; i++)
        cin >> ar[i];
    
    int mid = n / 2;
    vector<ll> ar1(ar.begin(), ar.begin() + mid);
    vector<ll> ar2(ar.begin() + mid, ar.end());
    vector<ll> ss1 = get_ss(ar1);
    vector<ll> ss2 = get_ss(ar2);
    sort(ss2.begin(), ss2.end());
    ll res = 0;
    for(ll x : ss1){
        ll start = a - x;
        ll end = b - x;
        res += (upper_bound(ss2.begin(), ss2.end(), end) - lower_bound(ss2.begin(), ss2.end(), start));
    }
    cout << res << "\n";
    return 0;
}