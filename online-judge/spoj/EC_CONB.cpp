#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool is(int x, int pos){
    return (x & (1 << pos)) > 0;
}
int rev(int x){
    int b = 31;
    for(b; b >= 0; --b){
        if(is(x, b)) break;
    }
    int res = 0;
    for(int c = 0; b >= 0; --b, c++){
        if(is(x,b)){
            res = res | (1 << c);
        }
    }
    return res;
}

int main(){
    fast
    int n,x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x & 1){
            cout << x << "\n";
        }else{
            cout << rev(x) << "\n";
        }
    }
    return 0;
}