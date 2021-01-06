class Solution {
    public boolean good(int[] weights, int mx, int D){
        int cw = 0;
        int d = 0;
        int n = weights.length;
        for(int i = 0; i < n; i++){
            cw += weights[i];
            if(cw > mx){
                d++;
                cw = weights[i];
                if(cw > mx){
                    return false;
                }
            }
        }
        return ++d <= D;
    }
    public int shipWithinDays(int[] weights, int D) {
        int lo = Arrays.stream(weights).max().getAsInt();
        int hi = Arrays.stream(weights).sum();
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(good(weights, mid, D)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
}