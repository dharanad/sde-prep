import java.util.*;

public class ExtraLargeFactorial {
    private static BigInteger[] fact;
    
    static void preCompute(){
        fact = new BigInteger[101];
        fact[1] = BigInteger.ONE;
        for(int i = 2; i <= 100; i++){
            fact[i] = new BigInteger(Integer.toString(i)).multiply(fact[i-1]);
        }
    }
    
    static void extraLongFactorials(int n) {
        System.out.println(fact[n].toString());
    }

    public static void main(String ...args){
        preCompute();

    }
}