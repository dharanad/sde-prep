#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(vector<int> &ar, int n){
    int res = 0;
    for(int i = n - 1; i >= 0; --i){
        int val = i + 1;
        if(ar[i] != val){
            if((i-1 >= 0) && ar[i-1] == val){
                swap(ar[i], ar[i-1]);
                res += 1;
            }else if((i-2 >= 0) && ar[i-2] == val){
                swap(ar[i-2], ar[i-1]);
                swap(ar[i-1], ar[i]);
                res += 2;
            }else{
                cout << "Not Allowed";
                return;
            }
        }
    }
    cout << res;
}
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        solve(ar, n);
        cout << "\n";
    }
}