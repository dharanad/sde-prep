import java.util.*;

public class ClimbingLeaderBoard {
    static int bs(List<Integer> ranked, int lo, int hi, Integer val){
        while(lo < hi){
            int mid = lo + (hi - lo + 1) / 2;
            if(ranked.get(mid) >= val){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }
    public static List<Integer> climbingLeaderboard(List<Integer> ranked, List<Integer> player) {
        List<Integer> res = new LinkedList<>();
        int n = ranked.size();
        int lo = 0;
        int hi = 0;
        for(int i = 1; i < n; i++){
            if(!ranked.get(i).equals(ranked.get(hi))){
                hi++;
                ranked.add(hi, ranked.remove(i));
            }
        }
        ranked.add(-1); // dummy node
        for(Integer val : player){
            int pos = bs(ranked, lo, hi, val);
            if(!ranked.get(pos).equals(val)){
                if(pos == 0){
                    ranked.add(0, val);
                    res.add(1);
                }else{
                    ranked.add(pos + 1, val);
                    res.add(pos + 2);
                }
                hi++;
            }else{
                res.add(pos + 1);
            }
        }
        return res;
    }

    public static void main(String ...args){
        List<Integer> ranked = new LinkedList<>();
        ranked.add(100);
        ranked.add(100);
        ranked.add(50);
        ranked.add(40);
        ranked.add(40);
        ranked.add(20);
        ranked.add(10);
        List<Integer> player = new LinkedList<>();
        player.add(5);
        player.add(25);
        player.add(50);
        player.add(120);
        climbingLeaderboard(ranked, player).forEach(System.out::println);
    }
} 