#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
bool good(vector<ll> &ar, int k, ll limit, int i = 0){
    int n = ar.size();
    int cnt = 1;
    ll pages = 0;
    for(i; i < n; i++){
        pages += ar[i];
        if(pages > limit){
            cnt++;
            pages = ar[i];
            if(pages > limit){
                return false;
            }
        }
    }
    return cnt <= k;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<ll> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        
        ll lo = *max_element(ar.begin(), ar.end());
        ll hi = accumulate(ar.begin(), ar.end(), 0);
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(good(ar, k, mid)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        for(int i = 0; i < n; i++){
            cout << ar[i] << " ";
            if(k > 1 && good(ar, k - 1, lo, i + 1)){
                k--;
                cout << "/ ";
            }
        }
        cout << "\n";
    }
    return 0;
}