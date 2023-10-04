
class Solution {
    int M, N, eCount=1, res=0;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size(), N=grid[0].size();
        int x, y;
        for (int i=0; i < M; i++)
            for (int j=0; j<N; j++){
                if (grid[i][j] ==1) x= i, y=j;
                else if (grid[i][j] ==0) eCount++;
            }

        DFS(grid, x,y,0);
        return res;        
    }

    void DFS(vector<vector<int>>& g, int i, int j,int count){
        if ( i < 0 || i >= M ||  j < 0 || j >= N || g[i][j] == -1) return;

        if(g[i][j] == 2){
            if (count == eCount) res++;
            return;
        }
        g[i][j] = -1;
        count++;
        DFS(g,i+1,j,count);
        DFS(g,i-1,j,count);
        DFS(g,i,j+1,count);
        DFS(g,i,j-1,count);
        g[i][j] = 0;
    }
};
