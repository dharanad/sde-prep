#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string get_text(vector<int> &ar, int n){
    string res(n-1);
    for(int i = 1; i < n; i++){
        char r;
        if(ar[i] > ar[i-1]){
            r = 'G'; 
        }else if(ar[i] < ar[i-1]){
            r = 'L';
        }else{
            r = 'E';
        }
        res[i-1] = r;
    }
    return res;
}

vector<int> get_lps(string &pattern){
    int n = pattern.size();
    vector<int> PI(n);
    int i =  1;
    int j = 0;
    while(i < n){
        if(pattern[i] == pattern[j]){
            PI[i++] = ++j;
        }else{
            if(j != 0){
                j = PI[j-1];
            }else{
                PI[i++] = 0;
            }
        }
    }
    return PI;
}

bool kmp(string &text, string &pattern){
    int patternLength = pattern.size();
    int n = text.size();
    vector<int> LPS = get_lps(pattern);
    int i = 0;
    int j = 0;
    while(i < n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = LPS[j-1];
            }else{
                i++;
            }
        }
        if(j == patternLength){
            return true;
        }
    }
    return false;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i=0;i<n;i++)
            cin >> ar[i];
        string pat; cin >> pat;
        string text = get_text(ar,n);
        if(kmp(text, pat)){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}