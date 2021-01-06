import java.util.*;

public class SumOfArray {
    public static void sovle(int x){
        int res = 0;
        Queue<Integer> q = new Queue<>();
        q.add(x);
        while(!q.isEmpty()){
            int u = q.poll();
            for(int v : adj.get(u)){
                if(!vis[v]){
                    q.add(v);
                    vis[v] = true;
                }
            }
        }
        System.out.println(res);
    }
    public static void main(String ...args){
        Reader in = new BufferedReader(new InputStreamReader(System.in));
        while(in.readLine() != -1){
            int n = Integer.parseInt(in.read());
            solve(n);
        }
    }
}