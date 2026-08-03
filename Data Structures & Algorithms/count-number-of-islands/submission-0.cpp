class Solution {

public:
    int n,m;
    int numIslands(vector<vector<char>>& grid) {
         n= grid.size();
         m = grid[0].size();
        int cnt= 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(!vis[r][c] && grid[r][c]=='1'){
                    bfs(grid,r,c,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void bfs(vector<vector<char>>&grid,int row,int col,vector<vector<int>>& vis){
        vis[row][col] = 1;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc] && grid[nr][nc]=='1'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
         }
    }
};
