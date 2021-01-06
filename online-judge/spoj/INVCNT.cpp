#include <vector>
#include <iostream>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
ll res = 0;

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
    int i = 0, j = 0;
    int pos = start;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){ // i < j and a[i] <= b[j];
            ar[pos++] = a[i++];
        }else{ // i < j and a[i] > b[j]
            res += (n1 - i);
            ar[pos++] = b[j++];
        }
    }
    while(i < n1){
        ar[pos++] = a[i++];
    }
    while(j < n2){
        ar[pos++] = b[j++];
    }
}

void merge_sort(vector<int> &ar, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        merge_sort(ar, start, mid);
        merge_sort(ar, mid + 1, end);
        merge(ar, start, mid, end);
    }
}

ll solve(vector<int> &ar, int n){
    res = 0;
    merge_sort(ar, 0, n - 1);
    return res;
}
int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        cout << solve(ar, n) << "\n";
    }
    return 0;
}