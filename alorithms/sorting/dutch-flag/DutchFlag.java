import java.util.*;

public class DutchFlag {
    static int[] partition(int[] arr, int key){
        int n = arr.length;
        int lo = 0;
        int hi = n - 1;
        for(int mi = 0; mi <= hi; mi++){
            if(arr[mi] < key){
                int t = arr[lo];
                arr[lo] = arr[mi];
                arr[mi] = t;
                lo++;
            }else if(arr[mi] > key){
                int t = arr[hi];
                arr[hi] = arr[mi];
                arr[mi] = t;
                hi--;
                mi--;
            }
        }
        return arr;
    }

    public static void main(String ...args){
        int[] arr = {4,1,2,3,5,6,7,4,9,13,-1};
        arr = partition(arr, 4);
        for(int x : arr)
            System.out.print(x + " ");
        System.out.println();
    }
}