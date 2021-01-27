#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
/*
bool good(vector<int> &ar, int lim, int sz){
    int s = 0;
    for(int i = 0; i < sz; i++){
        s += ar[i];
    }
    if(s <= lim){
        return true;
    }
    for(int i = sz; i < ar.size(); i++){
        s -= ar[i - sz];
        s += ar[i];
        if(s <= lim){
            return true;
        }
    }
    return false;
}
 
vector<int> get_ans(vector<int> &ar, int lim, int sz){
    vector<int> res;
    int s = 0;
    for(int i = 0; i < sz; i++){
        s += ar[i];
    }
    if(s <= lim){
        res.push_back(s);
    }
    for(int i = sz; i < ar.size(); i++){
        s -= ar[i - sz];
        s += ar[i];
        if(s <= lim){
            res.push_back(s);
        }
    }
    return res;
}
 
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> st(n);
        for(int i = 0; i < n; i++)
            cin >> st[i];
        int lo = 0;
        int hi = n;
        while(lo < hi){
            int mid = lo + (hi - lo + 1) / 2;
            if(good(st, m, mid)){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        if(lo == 0){
            cout << 0 << " " << 0 << "\n";
        }else{
            auto p_ans = get_ans(st, m, lo);
            cout << *min_element(p_ans.begin(), p_ans.end()) << " " << lo << "\n";
        }
    }
    return 0;
} 
*/
 
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> st(n);
        for(int i = 0; i < n; i++)
            cin >> st[i];
        int mx_ppl = INT_MAX, mx_len = 0;
        int s = 0;
        int ppl = 0;
        for(int e = 0; e < n; e++){
            ppl += st[e];
            while(ppl > m && s <= e){
                ppl -= st[s++];
            }
            int len = e - s + 1;
            if(len > mx_len){
                mx_ppl = ppl;
                mx_len = len;
            }else if(len == mx_len){
                mx_ppl = min(mx_ppl, ppl);
            }
        }
        cout << mx_ppl << " " << mx_len << "\n";
    }
    return 0;
} 