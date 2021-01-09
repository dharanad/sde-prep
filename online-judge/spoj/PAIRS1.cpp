#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar.begin(), ar.end());
    long long res = 0;
    for(int i = 0; i < n; i++){
        int x = ar[i] - k;
        int cnt = upper_bound(ar.begin(), ar.end(), x) - lower_bound(ar.begin(), ar.end(), x);
        res += cnt;
    }
    cout << res << "\n";
    return 0;
}