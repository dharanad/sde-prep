#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
ll ar[101];
int main(){
    fast
    for(int i = 1; i <= 100; i++){
        ar[i] = pow(i, 2);
    }
    for(int i = 1; i <= 100; i++){
        ar[i] += ar[i-1];
    }
    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        cout << ar[n] << "\n";
    }
    return 0;
}