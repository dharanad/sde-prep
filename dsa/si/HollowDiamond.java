import java.util.*;
import java.io.*;

public class HollowDiamond {
    static int iThOdd(int x){
        return 2 * x - 1;
    }
    static void printPattern(int n){
        int h1 = n / 2 + 1;
        for(int i = 1; i <= h1; i++){
            for(int k = 0; k < h1 - i; k++){
                System.out.print(" ");
            }
            System.out.print("*");
            if(i > 1){
                for(int k = 0; k < iThOdd(i-1); k++){
                    System.out.print(" ");
                }
                System.out.print("*");
            }
            System.out.println();
        }
        int h2 = n / 2;
        for(int i = h2; i >= 1; --i){
            for(int k = 0; k < h1 - i; k++){
                System.out.print(" ");
            }
            System.out.print("*");
            if(i > 1){
                for(int k = 0; k < iThOdd(i-1); k++){
                    System.out.print(" ");
                }
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public static void main(String ...args) throws IOException {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int tc = 1;
        while(t-- > 0){
            int n = in.nextInt();
            System.out.println("Case #" + Integer.toString(tc++) + ":");
            printPattern(n);
        }

    }
}