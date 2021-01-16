/*
For a triangle
a + b > 
a + c > b
b + c > a

if a < b < c
a + b > c then a,b,c can form a triable

for degenrate triange a + b >= c

In these problem we need to find all triplets
where a + b < c
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    fast
    int n;
    while(cin >> n && n != 0){
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        sort(ar.begin(), ar.end());
        long long res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int val = ar[i] + ar[j];
                int cnt = ar.end() - upper_bound(ar.begin(), ar.end(), val);
                res += cnt;
            }
        }
        cout << res << "\n";
    }
}
