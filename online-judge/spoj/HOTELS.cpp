#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
int main(){
    fast
    ll n, m;
    cin >> n >> m;
    vector<ll> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    ll res = -1;
    ll sum = 0;
    int start = 0;
    for(int end = 0; end < n; end++){
        sum += ar[end];
        while(sum > m && start <= end){ // trim
            sum -= ar[start++];
        }
        res = max(res, sum);
    }
    cout << res << "\n";
    return 0;
}