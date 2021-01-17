#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ar[n];
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        sort(ar, ar + n);
        int res = INT_MAX;
        for(int i = 0; i < n - k + 1; i++){
            res = min(res, ar[i + k - 1] - ar[i]);
        }
        cout << res << "\n";
    }
    return 0;
}