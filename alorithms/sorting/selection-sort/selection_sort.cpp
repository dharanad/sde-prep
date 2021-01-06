#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

void selection_sort(vector<int> &arr, int size){
    if(size == 0){
        return;
    }
    for(int idx = 0; idx < size - 1; idx++){
        int min_idx = idx; // lets assume min ele be at curr index
        for(int r_idx = idx + 1; r_idx < size; r_idx++){
            if(arr[r_idx] < arr[min_idx]){ // try to find ele lt ele at min_idx
                min_idx = r_idx;
            }
        }
        swap(arr[idx], arr[min_idx]);
    }
}

int main(){
    int size = 1e5;
    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        arr[i] = rand();
    }
    selection_sort(arr, size);
    if(is_sorted(arr.begin(), arr.end())){
        cout << "PASS";
    }else{
        cout << "FAIL";
    }
    return 0;
}