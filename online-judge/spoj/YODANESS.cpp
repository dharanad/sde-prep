#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

ll res;

void merge(vector<int> &ar, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<int> a(n1), b(n2);
    for(int i = 0; i < n1; i++){
        a[i] = ar[start + i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = ar[mid + 1 + i];
    }
    int i = 0, j = 0, p = start;
    while(i <  n1 && j < n2){
        if(a[i] <= b[j]){
            ar[p++] = a[i++];
        }else{ // i < j and a[i] > b[j]
            res += (n1 - i);
            ar[p++] = b[j++];
        }
    }
    while(i < n1){
        ar[p++] = a[i++];
    }
    while(j < n2){
        ar[p++] = b[j++];
    }
}

void ms(vector<int> &ar, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        ms(ar, start, mid);
        ms(ar, mid + 1, end);
        merge(ar, start, mid, end);
    }
}

ll solve(vector<int> &ar, int n){
    res = 0;
    ms(ar, 0, n - 1);
    return res;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> yoda(n);
        unordered_map<string,int> hm;
        for(int i = 0; i < n; i++){
            cin >> yoda[i];
        }
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            hm[s] = i;
        }
        vector<int> ar(n);
        for(int i = 0; i < n; i++){
            ar[i] = hm[yoda[i]];
        }
        cout << solve(ar, n) << "\n";
    }
    return 0;
}