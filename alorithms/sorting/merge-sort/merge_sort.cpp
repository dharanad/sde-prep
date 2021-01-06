#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
const int MOD = 1e9 + 7;
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    int n = mid - start + 1;
    int m = end - mid;
    vector<int> left(n), right(m);
    for(int i = 0; i < n; i++){
        left[i] = arr[start + i];
    }
    for(int i = 0; i < m; i++){
        right[i] = arr[mid + i + 1];
    }
    int l_pos = 0, r_pos = 0, c_pos = start;
    while(l_pos < n && r_pos < m){
        if(left[l_pos] <= right[r_pos]){
            arr[c_pos] = left[l_pos];
            l_pos++;
        }else{
            arr[c_pos] = right[r_pos];
            r_pos++;
        }
        c_pos++;
    }
    while(l_pos < n){
        arr[c_pos] = left[l_pos];
        c_pos++;
        l_pos++;
    }
    while(r_pos < m){
        arr[c_pos] = right[r_pos];
        c_pos++;
        l_pos++;
    }
}

// i -> [start, end]
void merge_sort(vector<int> &arr, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge_sort(vector<int> &arr, int size){
    merge_sort(arr, 0, size - 1);
}

int main(){
    int size = 1e5;
    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        arr[i] = rand() % MOD;
    }
    merge_sort(arr, size);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "PASS";
    }else{
        cout << "FAIL";
    }
    return 0;
}