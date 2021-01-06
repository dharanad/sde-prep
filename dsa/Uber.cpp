#include <iostream>
#include <string>
#include <vector>
using namespace std;

char get(int i){
    switch(i){
        case 0:
            return '+';
        case 1:
            return '-';
        case 2:
            return '*';
        default:
            return '/';
    }
}

void generate(string &s, int idx, vector<bool> &taken, int n){
    if(idx == n){
        cout << s << "\n";
        return;
    }
    for(int i = 0; i < 4; i++){
        if(!taken[i]){
            taken[i] = true;
            s[idx] = get(i);
            generate(s, idx + 2, taken, n);
            taken[i] = false;
        }
    }
}

// 1 2 3
// 1 x 2 x 3
// 1 x 2

int main(){
    string s; cin >> s;
    int n = 2 * s.size() - 1;
    string temp(n,' ');
    int j = 0;
    for(int i = 0; i < n; i++){
        if(!(i & 1)){
            temp[i] = s[j++];
        }
    }
    vector<bool> taken(4, false);
    generate(temp, 1, taken, n);
    return 0;
}