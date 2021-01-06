import java.util.*;
public class InsertionSort {
    static void insertionSort(ArrayList<Integer> arr, int size){
        for(int currIdx = 1; currIdx < size; currIdx++){
            int insertIdx = currIdx - 1;
            int key = arr.get(currIdx);
            while(insertIdx >= 0 && arr.get(insertIdx) > key){
                arr.add(insertIdx + 1, arr.get(insertIdx));
                insertIdx--;
            }
            if(insertIdx + 1 != currIdx){
                arr.add(insertIdx + 1, key);
            }
        }
    }
}