#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;

ll solve(string s){
    int n = s.size();
    vector<ll> dp(n+2, 0);
    
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        char c = s[i-1];
        char p = s[i-2];
        dp[i] = 0;
        if(c > '0')
            dp[i] = dp[i-1];
        if(p == '1' || (p == '2' && c <= '6')){
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}
int main(){
    fast
    string s;
    while(cin >> s){
        if(s == "0"){
            break;
        }
        cout << solve(s) << "\n";
    }
}