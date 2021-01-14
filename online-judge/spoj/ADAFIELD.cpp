#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<pi> vpi;
/*
2
10 10 5
0 5
0 8
1 1
1 9
1 5
10 10 5
0 5
1 4
1 6
1 8
0 5
*/

/*
Failing TC 12

Issue is when a line is add added and the field is divied in two equal halfs
And also Code is adding line to seg which has highest area, they might a new seg
which may have same value as highest segment and new field might not be added to it
which may result in wrong ans when current highest seg is further divied into small parts
How do i fix it ??
*/
// void solve(ll h, ll w, vector<pi> &query){
//     priority_queue<ppi> hq, wq;
//     hq.push(make_pair(h, make_pair(0,h)));
//     wq.push(make_pair(w, make_pair(0,w)));
//     for(pi &q : query){
//         int is_horizontal = q.first;
//         int d = q.second;
//         if(is_horizontal){ // will effect height line
//             ppi curr = hq.top();
//             ll lo = curr.second.first;
//             ll hi = curr.second.second;
//             if(d > lo && d < hi){
//                 hq.pop();
//                 ll h1 = d - lo;
//                 ll h2 = hi - d;
//                 hq.push(make_pair(h1, make_pair(lo, d)));
//                 hq.push(make_pair(h2, make_pair(d, hi)));
//             }
//         }else{
//             ppi curr = wq.top();
//             ll lo = curr.second.first;
//             ll hi = curr.second.second;
//             if(d > lo && d < hi){
//                 wq.pop();
//                 ll w1 = d - lo;
//                 ll w2 = hi - d;
//                 wq.push(make_pair(w1, make_pair(lo, d)));
//                 wq.push(make_pair(w2, make_pair(d, hi)));
//             }
//         }
//         ll h = hq.top().first;
//         ll w = wq.top().first;
//         cout << (h * w) << "\n";
//     }
// }
/*

    ------------------ x
    |
    |
    |
    |
    |
    y
*/
// void solve(ll h, ll w, vector<pi> &query){

// }
int main()
{
    fast 
    int t;
    cin >> t;
    while (t--)
    {
        ll w, h, q;
        cin >> w >> h >> q;
        vector<pi> query(q);
        multiset<ll> x_plane, y_plane, dx, dy;
        x_plane.insert(0);
        x_plane.insert(w);
        y_plane.insert(0);
        y_plane.insert(h);
        dx.insert(w);
        dy.insert(h);
        int is_horizontal;
        int d;
        for (int i = 0; i < q; i++)
        {
            cin >> is_horizontal >> d;
            ll mx_h = *dy.rbegin();
            ll mx_w = *dx.rbegin();
            if (is_horizontal)
            { // y_plane
                if (y_plane.find(d) == y_plane.end())
                {
                    auto lo = y_plane.lower_bound(d);
                    --lo; // last element which is < d
                    auto hi = y_plane.upper_bound(d);
                    ll dist = *hi - *lo;
                    dy.erase(dy.find(dist));
                    dy.insert(*hi - d);
                    dy.insert(d - *lo);
                    y_plane.insert(d);
                }
                else
                {
                    cout << (mx_h * mx_w) << "\n";
                    continue;
                }
            }
            else
            { // x_plane
                if (x_plane.find(d) == x_plane.end())
                {
                    auto lo = x_plane.lower_bound(d);
                    --lo;
                    auto hi = x_plane.upper_bound(d);
                    ll dist = *hi - *lo;
                    dx.erase(dx.find(dist));
                    dx.insert(*hi - d);
                    dx.insert(d - *lo);
                    x_plane.insert(d);
                }
                else
                {
                    cout << (mx_h * mx_w) << "\n";
                    continue;
                }
            }
            mx_h = *dy.rbegin();
            mx_w = *dx.rbegin();
            cout << (mx_h * mx_w) << "\n";
        }
    }
    return 0;
}