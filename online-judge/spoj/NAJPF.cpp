#include <vector>
#include <iostream>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> get_lps(string const &pattern){
    int size = pattern.size();
    vector<int> PI(size);
    int i = 1;
    int j = 0;
    while(i < size){
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

vector<int> solve(string const &text, string const &pattern){
    vector<int> res;
    int textLength = text.size();
    int patternLength = pattern.size();
    if(patternLength > textLength){
        return res;
    }
    vector<int> LPS = get_lps(pattern);
    int textPos = 0;
    int patternPos = 0;
    while(textPos < textLength){
        if(text[textPos] == pattern[patternPos]){
            textPos++;
            patternPos++;
        }else{
            if(patternPos != 0){
                patternPos = LPS[patternPos - 1];
            }else{
                textPos++;
            }
        }
        if(patternPos == patternLength){
            int idx = textPos - patternLength + 1;
            res.push_back(idx);
            patternPos = 0;
        }
    }
    return res;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        auto res = solve(a,b);
        int sz = res.size();
        if(sz){
            cout << sz << "\n";
            for(int i : res){
                cout << i << " ";
            }
        }else{
            cout << "Not Found";;
        }
        cout << "\n";
    }
    return 0;
}