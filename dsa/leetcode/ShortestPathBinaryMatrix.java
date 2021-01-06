// https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/
// Approach #1
class Solution {
    class Pair {
        int first, second;
        int dist;
        public Pair(int f, int s, int d){
            this.first = f;
            this.second = s;
            this.dist = d;
        }
    }
    
    public boolean isSafe(int i, int j, int r, int c){
        if(i < 0 || j < 0 || i > r || j > c){
            return false;
        }
        return true;
    }
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        int r = grid.length - 1;
        int c = grid[0].length - 1;
        if(grid[0][0] == 1 || grid[r][c] == 1){
            return -1;
        }
        int[] xp = {-1,-1,-1,0,0,1,1,1};
        int[] yp = {-1,0,1,-1,1,-1,0,1};

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(0,0,1));
        grid[0][0] = 1;
        while(!q.isEmpty()){
            Pair curr = q.poll();
            int u = curr.first;
            int v = curr.second;
            int d = curr.dist;
            if(u == r && v == c){
                return d;
            }
            for(int k = 0; k < xp.length; k++){
                int nu = xp[k] + u;
                int nv = yp[k] + v;
                if(isSafe(nu, nv, r, c) && grid[nu][nv] == 0){
                    q.add(new Pair(nu, nv, d + 1));
                    grid[nu][nv] = 1;
                }
            }
        }
        return -1;
    }
}class Solution {
    class Pair {
        int first, second;
        int dist;
        public Pair(int f, int s, int d){
            this.first = f;
            this.second = s;
            this.dist = d;
        }
    }
    
    public boolean isSafe(int i, int j, int r, int c){
        if(i < 0 || j < 0 || i > r || j > c){
            return false;
        }
        return true;
    }
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        int r = grid.length - 1;
        int c = grid[0].length - 1;
        if(grid[0][0] == 1 || grid[r][c] == 1){
            return -1;
        }
        int[] xp = {-1,-1,-1,0,0,1,1,1};
        int[] yp = {-1,0,1,-1,1,-1,0,1};

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(0,0,1));
        grid[0][0] = 1;
        while(!q.isEmpty()){
            Pair curr = q.poll();
            int u = curr.first;
            int v = curr.second;
            int d = curr.dist;
            if(u == r && v == c){
                return d;
            }
            for(int k = 0; k < xp.length; k++){
                int nu = xp[k] + u;
                int nv = yp[k] + v;
                if(isSafe(nu, nv, r, c) && grid[nu][nv] == 0){
                    q.add(new Pair(nu, nv, d + 1));
                    grid[nu][nv] = 1;
                }
            }
        }
        return -1;
    }
}

// # Approach 2
class Solution {
    class Pair {
        int first, second;
        public Pair(int f, int s){
            this.first = f;
            this.second = s;
        }
    }
    
    public boolean isSafe(int i, int j, int r, int c){
        if(i < 0 || j < 0 || i > r || j > c){
            return false;
        }
        return true;
    }
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        int r = grid.length - 1;
        int c = grid[0].length - 1;
        if(grid[0][0] == 1 || grid[r][c] == 1){
            return -1;
        }
        int[] xp = {-1,-1,-1,0,0,1,1,1};
        int[] yp = {-1,0,1,-1,1,-1,0,1};

        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(0,0));
        grid[0][0] = 1;
        while(!q.isEmpty()){
            Pair curr = q.poll();
            int u = curr.first;
            int v = curr.second;
            if(u == r && v == c){
                return grid[r][c];
            }
            for(int k = 0; k < xp.length; k++){
                int nu = xp[k] + u;
                int nv = yp[k] + v;
                if(isSafe(nu, nv, r, c) && grid[nu][nv] == 0){
                    q.add(new Pair(nu, nv));
                    grid[nu][nv] = grid[u][v] + 1;
                }
            }
        }
        return -1;
    }
}