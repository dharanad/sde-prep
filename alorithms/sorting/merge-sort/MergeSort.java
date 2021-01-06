import java.util.*;

public class MergeSort {
    /*
        x x x x x x x x x x x x x
        s         m             e   
     */
    static void merge(ArrayList<Integer> arr, int start, int mid, int end){
        int n = mid - start + 1;
        int m = end - mid;
        int[] left = new int[n];
        int[] right = new int[m];
        for(int i = 0; i < n; i++){
            left[i] = arr.get(start + i);
        }
        for(int i = 0; i < m; i++){
            right[i] = arr.get(mid + 1 + i);
        }
        int leftPos = 0;
        int rightPos = 0;
        int currIdx = start;
        while(leftPos < n && rightPos < m){
            if(left[leftPos] <= right[rightPos]){
                arr.add(currIdx, left[leftPos]);
                leftPos++;
            }else{
                arr.add(currIdx, right[rightPos]);
                rightPos++;
            }
            currIdx++;
        }
        while(leftPos < n){
            arr.add(currIdx, left[leftPos]);
            leftPos++;
            currIdx++;
        }
        while(rightPos <  m){
            arr.add(currIdx, right[rightPos]);
            rightPos++;
            currIdx++;
        }
    }
    static void mergeSort(ArrayList<Integer> arr, int start, int end){
        if(start < end){
            int mid = start + (end - start) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid+1, end);
            merge(arr, start, mid, end);
        }
    }

    static void mergeSort(ArrayList<Integer> arr){
        int end = arr.size() - 1;
        mergeSort(arr, 0, end);
    }

    // static ArrayList<Integer> mergeSort(ArrayList<Integer> arr){
    //     int size = arr.size();
    //     if(size <= 1) return arr;
    //     int mid = size / 2;
    //     ArrayList<Integer> left = mergeSort(new ArrayList<>(arr.subList(0, mid)));
    //     ArrayList<Integer> right = mergeSort(new ArrayList<>(arr.subList(mid, size)));
    //     return merge(left, right);
    // }

    // static ArrayList<Integer> merge(ArrayList<Integer> left, ArrayList<Integer> right){
    //     int n = left.size();
    //     int m = right.size();
    //     ArrayList<Integer> res = new ArrayList<>(n + m);
    //     int leftIdx = 0;
    //     int rightIdx = 0;
    //     int currIdx = 0;
    //     while(leftIdx < n && rightIdx < m){
    //         if(left.get(leftIdx) <= right.get(rightIdx)){
    //             res.add(currIdx, left.get(leftIdx));
    //             leftIdx++;
    //         }else{
    //             res.add(currIdx, right.get(rightIdx));
    //             rightIdx++;
    //         }
    //         currIdx++;
    //     }
    //     while(leftIdx < n){
    //         res.add(currIdx, left.get(leftIdx));
    //         leftIdx++;
    //         currIdx++;
    //     }
    //     while(rightIdx < m){
    //         res.add(currIdx, right.get(rightIdx));
    //         rightIdx++;
    //         currIdx++;
    //     }
    //     return res;
    // }

    // static ArrayList<Integer> mergeSort(ArrayList<Integer> arr){
    //     int end = arr.size() - 1;
    //     return mergeSort(arr, 0, end);
    // }

    public static void main(String ...args){
        Random rand = new Random();
        int size = (int) 1e4;
        ArrayList<Integer> arr = new ArrayList<>(size);
        for(int i = 0; i < size; i++){
            arr.add(i, rand.nextInt());
        }
        mergeSort(arr);
        boolean flag = true;
        for(int i = 1; i < size - 1; i++){
            if(arr.get(i - 1).compareTo(arr.get(i)) > 0){
                flag = false;
                break;
            }
        }
        if(flag){
            System.out.println("PASS");
        }else{
            System.out.println("FAIL");
        }
    }
}