#include <iostream>
#include <vector>
#include <string>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector<int> get_lps(string const &needle){
    int len = needle.size();
    vector<int> pi(len);
    int j = 0;
    int i = 1;
    while(i < len){
        if(needle[i] == needle[j]){
            pi[i++] = ++j;
        }else{
            if(j != 0){
                j = pi[j-1];
            }else{
                pi[i++] = 0;
            }
        }
    }
    return pi;
}

vector<int> find_occurences(string const &needle, string const &haystack){
    vector<int> res;
    vector<int> LPS = get_lps(needle);
    int nl = needle.size();
    int hl = haystack.size();
    int i = 0, j = 0;
    while(i < hl){
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = LPS[j-1];
            }else{
                i++;
            }
        }
        if(j == nl){
            int idx = i - j;
            res.push_back(idx);
            j = 0; i = idx + 1;
        }
    }
    return res;
}

int main(){
    fast
    int s;
    string needle, haystack;
    while(cin >> s){
        cin >> needle;
        cin >> haystack;
        for(int i : find_occurences(needle, haystack)){
            cout << i << "\n";
        }
        cout << "\n";
    }
    return 0;
}
