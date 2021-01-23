#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int solve(string &a, string &b, int idxA, int idxB){
    // if(idxA == 0){
    //     return idxB;
    // }
    // if(idxB == 0){
    //     return idxA;
    // }
    // if(a[idxA-1] == b[idxB - 1]){
    //     return solve(a, b, idxA - 1, idxB - 1);
    // }
    // return 1 + min(solve(a,b,idxA - 1, idxB), 
    //     min(solve(a,b,idxA, idxB - 1),solve(a,b,idxA - 1, idxB - 1))
    // );
    int dp[idxA + 1][idxB + 1];
    dp[0][0] = 0;
    for(int i = 1; i <= idxA; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= idxB; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= idxA; i++){
        for(int j = 1; j <= idxB; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    return dp[idxA][idxB];
}

int main(){
    int t; cin >> t;
    string a, b;
    while(t--){
        cin >> a >> b;
        int idxA = a.size();
        int idxB = b.size();
        cout << solve(a, b, idxA, idxB) << "\n";
    }
    return 0;
}