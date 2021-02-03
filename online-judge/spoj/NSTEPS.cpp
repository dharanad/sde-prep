#include <iostream>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    fast
    int x, y;
    int t; cin >> t;
    while(t--){
        cin >> x >> y;
        if(x == y || x == (y-2)){
            if(x & 1){
                --x;
            }
            cout << (x + y) << "\n";
        }else{
            cout << "No Number";
        }
        cout << "\n";
    }
    return 0;
}