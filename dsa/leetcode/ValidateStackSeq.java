class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stk = new Stack<>();
        int n = pushed.length;
        int j = 0;
        for(int i = 0; i < n; i++){
            stk.push(pushed[i]);
            while(!stk.empty() && j < n && popped[j] == stk.peek()){
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
}