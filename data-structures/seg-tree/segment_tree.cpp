#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e5;

int seg[4 * N + 5];

void build(vector<int> &ar, int start, int end, int pos = 1){
    if(start == end){
        seg[pos] = ar[start];
        return;
    }
    int mid = start + (end - start) / 2;
    int lc = pos << 1;
    int rc = pos << 1 | 1;
    build(ar, start, mid, lc);
    build(ar, mid + 1, end, rc);
    seg[pos] = seg[lc] + seg[rc];
}

int find_s(int L, int R, int start, int end, int pos = 1){
    if(start > R || end < L){
        return 0;
    }
    if(start >= L && end <= R){
        return seg[pos];
    }
    int mid = start + (end - start) / 2;
    int lc = 2 * pos;
    int rc = 2 * pos + 1;
    return find_s(L, R, start, mid, lc) + find_s(L, R, mid + 1, end, rc);
}

int main(){
    fast
    int n; cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    build(ar, 0, n - 1);
    int q; cin >> q;
    int i, j;
    while(q--){
        cin >> i >> j;
        cout << find_s(i, j, 0, n - 1) << "\n";
    }
    return 0;
}