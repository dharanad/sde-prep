#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <utility>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<vector<char>> grid;
typedef pair<int,int> pi;
typedef pair<int, pi> ppi;
const int X[] = {0,0,-1,1};
const int Y[] = {-1,1,0,0};
bool isSafe(int x, int y, int n, int m){
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}
int solve(grid &shop, int n, int m){
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    int i,j;
    bool f = false;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(shop[i][j] == 'S'){
                f = true;
                break;
            }
        }
        if(f) break;
    } // find src
    priority_queue<ppi, vector<ppi>, greater<ppi>> minQ; // min heap
    dist[i][j] = 0; // distance from src src
    minQ.push(make_pair(0, make_pair(i,j)));
    while(!minQ.empty()){
        ppi curr = minQ.top(); minQ.pop(); // i, j is removed from minQ then its min distance is already found
        int d = curr.first;
        int ux = curr.second.first;
        int uy = curr.second.second;
        if(shop[ux][uy] == 'D'){
            return dist[ux][uy]; // min waiting time from src to dest found
        }
        // if(d > dist[ux][uy]) continue;
        for(i = 0; i < 4; i++){
            int nx = ux + X[i];
            int ny = uy + Y[i];
            if(isSafe(nx, ny, n, m) && shop[nx][ny] != 'X'){
                // int nd = (shop[nx][ny] - '0') + d;
                int nd;
                if(shop[nx][ny] == 'D'){
                    nd = 0;
                }else{
                    nd = shop[nx][ny] - '0';
                }
                nd += d;
                if(nd < dist[nx][ny]){
                    dist[nx][ny] = nd;
                    minQ.push(make_pair(nd, make_pair(nx, ny)));
                }
            }
        }
    }
    return INT_MAX;
}
int main(){
    fast
    int w,h;
    while(cin >> w && cin >> h){
        if(w == 0 && h == 0){
            break;
        }
        grid shop(h, vector<char>(w));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                cin >> shop[i][j];
        }
        cout << solve(shop, h, w) << "\n";
    }
    return 0;
}