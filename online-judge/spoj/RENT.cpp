#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef long long ll;
bool cmp(pii &a, pii& b){
    return a.first.second < b.first.second;
}
int bs(vector<pii> &ar, int start, int end, int val){
    while(start < end){
        int mid = start + (end - start + 1) / 2;
        if(ar[mid].first.second <= val){
            start = mid;
        }else{
            end = mid - 1;
        }
    }
    return (ar[start].first.second <= val) ? start + 1: 0;
}
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pii> ar(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i].first.first >> ar[i].first.second >> ar[i].second;
            ar[i].first.second += ar[i].first.first;
        }
        sort(begin(ar), end(ar), cmp);
        vector<ll> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1];
            pii curr = ar[i-1];
            int start = curr.first.first;
            int cost = curr.second;
            int pos = bs(ar, 0, n - 1, start);
            dp[i] = max(dp[i],(ll) cost + dp[pos]);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}