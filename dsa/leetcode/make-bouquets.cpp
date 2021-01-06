// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
private:
    bool check(vector<int>& bloomDay,int d, int m, int k){
        int n = bloomDay.size();
        int bq = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] > d){
                cnt = 0;
            }else if(++cnt == k){
                bq++;
                cnt = 0;
            }
        }
        return bq >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1;
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(check(bloomDay, mid, m, k)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return check(bloomDay, lo, m, k) ? lo : -1;
    }
};