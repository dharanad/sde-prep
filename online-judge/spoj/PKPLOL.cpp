#include <iostream>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string solve(int x){
    if(x == 0){
        return "abcdef";
    }else if(x == 1){
        return "bc";
    }else if(x == 2){
        return "abdeg";
    }else if(x == 3){
        return "abcdg";
    }else if(x == 4){
        return "bcfg";
    }else if(x == 5){
        return "acdfg";
    }else if(x == 6){
        return "acdefg";
    }else if(x == 7){
        return "abc";
    }else if(x == 8){
        return "abcdefg";
    }
    return "abcdfg";
}
int main(){
    int t; cin >> t;
    int x;
    int tc = 1;
    while(t--){
        cin >> x;
        cout << "Case " << (tc++) << ": " << solve(x) << "\n";
    }
}