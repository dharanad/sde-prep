#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

// we check that can we make x col st they contain r and b
// that me we should have r >= x and b >= x and (r+g+b) >= 3*x

bool good(ll x, ll r, ll g, ll b){
    return (r>=x && b>=x && (r+g+b)>=3*x);
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        ll n, r, g, b;
        cin >> n >> r >> g >> b;
        ll lo = 0;
        ll hi = n;
        while(lo < hi){
            ll mid = lo + (hi - lo + 1) / 2;
            if(good(mid, r, g, b)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        cout << lo << "\n";
    }
    return 0;
}