import java.util.*;

/*
Convert the input matrix input to 1D matrix
Generate all the permutation of 1D matrix containing integer from [1,9]
For each permutation check if it is magic square
If yes compute the cost with the input matrix
And find the min cost
 */

public class MagicSquare {
    static boolean isMagicSquare(int[] arr){
        int r1 = arr[0] + arr[1] + arr[2];
        int r2 = arr[3] + arr[4] + arr[5];
        int r3 = arr[6] + arr[7] + arr[8];

        int c1 = arr[0] + arr[3] + arr[6];
        int c2 = arr[1] + arr[4] + arr[7];
        int c3 = arr[2] + arr[5] + arr[8];

        int d1 = arr[0] + arr[4] + arr[8];
        int d2 = arr[2] + arr[4] + arr[6];
        
        int[] check = {r1, r2, r3, c1, c2, c3, d1, d2};
        return Arrays.stream(check).allMatch(value -> value == check[0]);
    }
    
    static void generateAllPermutation(int[] arr, int idx, boolean[] taken, ArrayList<ArrayList<Integer>> op){
        if(idx == 9){
            if(isMagicSquare(arr)){
                ArrayList<Integer> res = new ArrayList<>();
                for (int j : arr) {
                    res.add(j);
                }
                op.add(res);
            }
            return;
        }
        for(int i = 1; i <= 9; i++){
            if(!taken[i]){
                taken[i] = true;
                arr[idx] = i;
                generateAllPermutation(arr, idx + 1, taken, op);
                taken[i] = false;
            }
        }
    }

    static int formingMagicSquare(int[][] s) {
        ArrayList<ArrayList<Integer>> op = new ArrayList<>();
        int[] arr = new int[9];
        boolean[] taken = new boolean[10];
        generateAllPermutation(arr, 0, taken, op);
        int[] ipm = new int[9];
        int k = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                ipm[k++] = s[i][j];
            }
        }
        int cost = Integer.MAX_VALUE;
        for(ArrayList<Integer> curr : op){
            int localCost = 0;
            for(int i = 0; i < 9; i++){
                localCost += Math.abs(ipm[i] - curr.get(i));
            }
            cost = Math.min(cost, localCost);
        }
        return cost;
    }

    public static void main(){

    }
}