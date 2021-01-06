#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main(){
    fast
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<int> ar(n);
        for(int i = 0; i < n; i++){
            cin >> ar[i];
        }
        ll res = 0;
        for(int i = 1; i < n; i++){
            res += abs(ar[i-1]);
            ar[i] += ar[i-1];
        }
        cout << res << "\n";
    }
    return 0;
}