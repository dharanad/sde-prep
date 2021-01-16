#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,n)        for (i = 0; i < n; ++i)
#define rrep(i,k,n)     for (i = k; i >= n; --i)
#define w(x)            int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define inrange(i,a,b)  ((i >= min(a, b)) && (i <= max(a, b)))
#define fsb(index)      (index & -index)
#define all(x)          x.begin(), x.end()
#define in(x)           int x; cin >> x;
typedef long long       ll;
typedef pair<int,int>   pi;
typedef pair<int,pi>    ppi;
typedef pair<long,long> pl;
typedef vector<int>     vi;
typedef vector<pi>      vpi;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;

ll rev(ll x){
    ll res = 0;
    while(x){
        ll d = x % 10;
        res = (res * 10) + d;
        x /= 10;
    }
    return res;
}
int main() {
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll x, y;
    w(t){
        cin >> x >> y;
        cout << rev(rev(x) + rev(y)) << "\n";
    }
    return 0;
}