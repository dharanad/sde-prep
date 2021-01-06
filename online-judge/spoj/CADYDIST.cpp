#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    fast
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<int> c(n), p(n);
        for(int i=0;i<n;i++)
            cin >> c[i];
        for(int i=0;i<n;i++)
            cin >> p[i];
        sort(c.begin(), c.end(), greater<int>());
        sort(p.begin(), p.end());
        long long res = 0;
        for(int i=0;i<n;i++){
            long long pr = (long long) c[i] * p[i];
            res += pr;
        }
        cout << res << "\n";
    }
    return 0;
}