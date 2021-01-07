/*
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
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> pi;
const int N = 1e5;

vector<int> seg[4*N+5];

// build merge sort trees
void build(vector<pi> &ar, int start, int end, int pos = 1){
    if(start == end){
        seg[pos].push_back(ar[start].second);
        return;
    }
    int mid = start + (end - start) / 2;
    int lc = pos << 1;
    int rc = lc | 1;
    build(ar, start, mid, lc);
    build(ar, mid + 1, end, rc);
    merge(seg[lc].begin(), seg[lc].end(), seg[rc].begin(), seg[rc].end(), back_inserter(seg[pos]));
}

int query(int L, int R, int start, int end, int k, int pos = 1){
    if(start == end){
        return seg[pos][0];
    }
    int lc = pos << 1;
    int rc = lc | 1;
    int cnt = upper_bound(seg[lc].begin(),seg[lc].end(), R) - lower_bound(seg[lc].begin(), seg[lc].end(), L);
    int mid = start + (end - start) / 2;
    if(cnt >= k){ // cnt < k
        return query(L, R, start, mid, k, lc);
    }else{
        return query(L, R, mid + 1, end, k - cnt, rc);
    }
}

int main(){
    fast
    int n, q; cin >> n >> q;
    vector<pi> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i].first;
        ar[i].second = i;
    }
    vector<pi> temp (ar.begin(), ar.end());
    sort(ar.begin(), ar.end());
    build(ar,0,n-1);
    int s,e,k;
    while(q--){
        cin >> s >> e >> k;
        --s; --e;
        int pos = query(s,e,0,n-1, k);
        cout << temp[pos].first << "\n";
    }
    return 0;
}