// https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
    public boolean check(String word, String ss){
        int n = word.length();
        int m = ss.length();
        if(m == 0){
            return false;
        }
        for(int i = 0; i < n; i++){
            if(word.charAt(i) == ss.charAt(0)){
                int j = 0;
                for(; j < m && (j + i) < n; j++){
                    if(word.charAt(i + j) != ss.charAt(j)){
                        break;
                    }
                }
                if(j == m){
                    return true;
                }
            }
        }
        return false;
    }
    public List<String> stringMatching(String[] words) {
        List<String> res = new ArrayList<>();
        int n = words.length;
        for(int i = 0; i < n; i++){
            String ss = words[i];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                String word = words[j];
                if(check(word, ss)){ // S^2
                    res.add(ss);
                    break;
                }
            }
        }
        return res;
    }
}


class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> res = new ArrayList<>();
        for(String s : words){
            for(String w : words){
                if(s == w) continue;
                if(w.contains(s)){
                    res.add(s);
                    break;
                }
            }
        }
        return res;
    }
}