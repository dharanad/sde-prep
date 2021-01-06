#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N = 1e5;

vector<int> seg[4 * N + 5];

vector<int> merge(vector<int> &left, vector<int> &right){
    int n1 = left.size();
    int n2 = right.size();
    vector<int> res(n1 + n2);
    int i = 0, j = 0;
    int pos = 0;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            res[pos++] = left[i++];
        }else{
            res[pos++] = right[j++];
        }
    }
    while(i < n1){
        res[pos++] = left[i++];
    }
    while(j <  n2){
        res[pos++] = right[j++];
    }
    return res;
}

void build(vector<int> &ar, int start, int end, int pos = 1){
    if(start == end){
        seg[pos].push_back(ar[start]);
        return;
    }
    int mid = start + (end - start) / 2;
    int lc = pos << 1;
    int rc = pos << 1 | 1;
    build(ar, start, mid, lc);
    build(ar, mid + 1, end, rc);
    seg[pos] = merge(seg[lc], seg[rc]);
}

vector<int> query(int L, int R, int start, int end, int pos = 1){
    if(L > end || R < start){
        return {};
    }
    if(start >= L && end <= R){
        return seg[pos];
    }
    int mid = start + (end - start) / 2;
    int lc = pos << 1;
    int rc = pos << 1 | 1;
    vector<int> left = query(L, R, start, mid, lc);
    vector<int> right = query(L, R, mid + 1, end, rc);
    return merge(left, right);
}

int main(){
    fast
    int n, q;
    cin >> n >> q;
    vector<int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    build(ar, 0, n - 1);
    int s,e,k;
    while(q--){
        cin >> s >> e >> k;
        cout << query(s-1,e-1,0, n-1)[k-1] << "\n";
    }
    return 0;
}