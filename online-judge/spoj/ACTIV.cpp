#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <iomanip>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int mod = 1e8;
bool cmp(pi const &a, pi const &b){
    return a.second < b.second;
}
int bs(vector<pi> &ar, int lo, int hi, int start){
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(ar[mid].second <= start){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    return (ar[lo].second <= start) ? lo + 1 : 0;
}
int main(){
    fast
    int n;
    while(cin >> n && n != -1){
        vector<pi> act(n);
        for(int i = 0; i < n; i++){
            cin >> act[i].first >> act[i].second;
        }
        sort(act.begin(), act.end(), cmp);
        vector<ll> dp(n + 5, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int start = act[i-1].first;
            dp[i] = (1 + dp[i-1]) % mod;
            int pos = bs(act, 0, n-1, start);
            if(pos != 0)
                dp[i] = (dp[i] + dp[pos])%mod;
        }
        cout << setw(8) << setfill('0') << dp[n] << "\n";
    }
    return 0;
}