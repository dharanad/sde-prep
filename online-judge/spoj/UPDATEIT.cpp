#include <iostream>
#include <cstring>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int ar[10001];
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n, u;
        cin >> n >> u;
        memset(ar, 0, sizeof(ar));
        int l,r,x;
        for(int i = 0; i < u; i++){
            cin >> l >> r >> x;
            ar[l] += x;
            ar[r + 1] -= x;
        }
        for(int i = 1; i < n + 1; i++){
            ar[i] += ar[i-1];
        }
        int q; cin >> q;
        for(int i = 0; i < q; i++){
            cin >> l;
            cout << ar[l] << "\n";
        }
    }
    return 0;
}