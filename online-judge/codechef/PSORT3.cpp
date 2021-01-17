#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> pi;

bool cmp(pi const &a, pi const &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

const int N = 1e5 + 5;
ll A[N];
ll B[N];
pi C[N];
int main(){
    fast
    // ll t; cin >> t;
    // while(t--){
        ll n; cin >> n;
        for(ll i = 0; i < n; i++)
            cin >> A[i];
        for(ll i = 0; i < n; i++)
            cin >> B[i];
        for(ll i = 0; i < n; i++){
            C[i] = make_pair(A[i], B[i]);
        }
        sort(C, C + n, cmp);
        for(ll i = 0; i < n; i++){
            cout << C[i].first << " " << C[i].second << " ";
        }
        cout << "\n";
    // }
}