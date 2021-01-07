#include <iostream>
#include <cmath>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int dp[111][111];

void reset(){
    for(int i = 0; i < 111; i++){
        for(int j = 0; j < 111; j++){
            dp[i][j] = 0;
        }
    }
}

int _max(int a, int b, int c){
    if(a > b && a > c){
        return a;
    }
    else if(b > c){
        return b;
    }
    return c;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int row, col;
        cin >> row >> col;
        int ar[row][col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j <  col; j++){
                cin >> ar[i][j];
            }
        }
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                dp[i][j] = ar[i-1][j-1] + max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]);
            }
        }
        int res = dp[row][1];
        for(int i = 2; i <= col; i++){
            res = max(res, dp[row][i]);
        }
        cout << res << "\n";
        reset();
    }
    return 0;
}