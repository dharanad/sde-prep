#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

void insertion_sort(vector<int> &arr, int size){
    for(int c_idx = 1; c_idx < size; c_idx++){
        int i_idx = c_idx - 1; // insert index
        int key = arr[c_idx];
        while(i_idx >= 0 && arr[i_idx] > key){
            arr[i_idx+1] = arr[i_idx];
            i_idx--;
        }
        if(i_idx + 1 != c_idx)
            arr[i_idx + 1] = key;
    }
}

int main(){
    int size = 1e5;
    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        arr[i] = rand();
    }
    insertion_sort(arr, size);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "PASS";
    }else{
        cout << "FAIL";
    }
}