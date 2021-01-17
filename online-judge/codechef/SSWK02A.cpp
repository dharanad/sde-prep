#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        sort(ar.begin(), ar.end());
        int m1 = n / 2;
        ll cost = 0;
        ll mv1 = ar[m1];
        for(int i = 0; i < n; i++){
            cost += abs(ar[i] - mv1);
        }
        if(n&1){
            cout << cost << "\n";
        }else{
            int m2 = m1 - 1;
            ll mv2 = ar[m2];
            ll cost2 = 0;
            for(int i = 0; i < n; i++)
                cost2 += abs(ar[i] - mv2);
            cout << min(cost, cost2) << "\n";
        }

    }
    return 0;
}