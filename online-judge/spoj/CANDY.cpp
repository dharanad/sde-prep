#include <vector>
#include <iostream>
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){
    fast
    int n;
    while(true){
        cin >> n;
        if(n == -1) break;
        vector<int> ar(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> ar[i];
            sum += ar[i];
        }
        if(sum % n){
            cout << -1;
        }else{
            int avg = sum / n;
            int res = 0;
            for(int i = 0; i < n; i++){
                if(ar[i] < avg){
                    res += abs(ar[i] - avg);
                }
            }
            cout << res;
        }
        cout << "\n";
    }
    return 0;
}