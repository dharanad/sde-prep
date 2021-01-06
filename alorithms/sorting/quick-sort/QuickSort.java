import java.util.*;

public class QuickSort {

    static int partition(ArrayList<Integer> arr, int start, int end){
        int key = arr.get(end);
        int bound = start;
        for(int i = start; i < end; i++){
            if(arr.get(i) <= key){
                int temp = arr.get(bound);
                arr.add(bound, arr.get(i));
                arr.add(i, temp);
                bound++;
            }
        }
        int temp = arr.get(bound);
        arr.add(bound, arr.get(end));
        arr.add(end, temp);
        return bound;
    }

    static void quickSort(ArrayList<Integer> arr, int start, int end){
        if(start < end){
            int pivot = partition(arr, start, end);
            quickSort(arr, start, pivot - 1);
            quickSort(arr, pivot + 1, end);
        }
    }

    static void quickSort(ArrayList<Integer> arr){
        int end = arr.size() - 1;
        quickSort(arr, 0, end);
    }

    public static void main(String ...args){
        Random rand = new Random();
        int size = (int) 1e2;
        ArrayList<Integer> arr = new ArrayList<>(size);
        for(int i = 0; i < size; i++){
            arr.add(i, rand.nextInt());
        }
        quickSort(arr);
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