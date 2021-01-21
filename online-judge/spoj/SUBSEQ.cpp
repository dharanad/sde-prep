#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <vector>
#include <unordered_map>
typedef long long ll;
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum = 0;
        ll x, res = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 1; // handle edge case
        for(int i = 0; i < n; i++){
            cin >> x;
            sum += x;
            if(mp.find(sum - 47) != mp.end()){
                res += mp[sum - 47]; // curr prefixsum can be mapped with all the prev occurrences
            }
            mp[sum]++; // count occurrences of prefix
        }
        cout << res << "\n";
    }

    return 0;
}