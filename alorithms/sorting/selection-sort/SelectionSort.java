import java.util.*;

public class SelectionSort {
    static void swap(ArrayList<Integer> arr, int a, int b){
        int temp = arr.get(a);
        arr.add(a, arr.get(b));
        arr.add(b, temp);
    }
    public static void selectionSort(ArrayList<Integer> arr, int size){
        if(size == 0){
            return;
        }
        for(int currIdx = 0; currIdx < size - 1; currIdx++){
            int minIdx = currIdx;
            for(int rightIdx = currIdx + 1; rightIdx < size; rightIdx++){
                if(arr.get(rightIdx) < arr.get(minIdx)){
                    minIdx = rightIdx;
                }
            }
            swap(arr, currIdx, minIdx);
        }
    }
}