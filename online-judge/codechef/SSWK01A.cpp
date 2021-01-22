#include <iostream>
#include <vector>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
ll cnt = 0;

void merge(vector<int> &ar, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)
        left[i] = ar[start + i];
    for(int i = 0; i < n2; i++)
        right[i] = ar[mid + 1 + i];
    int pos = start;
    int i = 0, j = 0;
    // i -> start
    // j -> mid + 1
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            ar[pos++] = left[i++];
        }else{ // all the element in left are greater that current right[i]
            cnt += (n1 - i);
            ar[pos++] = right[j++];
        }
    }
    while(i < n1){
        ar[pos++] = left[i++];
    }
    while(j < n2){
        ar[pos++] = right[j++];
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

ll inv_count(vector<int> &ar, int n){
    cnt = 0;
    merge_sort(ar, 0, n-1);
    return cnt;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        
        cout << inv_count(ar, n) << "\n";
    }
    return 0;
}