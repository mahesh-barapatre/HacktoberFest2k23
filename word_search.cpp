class Solution {
public:
    bool dfs(int i,int j,int n,vector<vector<int>> &vis,vector<vector<char>> &board,
    string word){
        if(n==word.size())return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]||
        board[i][j]!=word[n]){
            return false;
        }
        vis[i][j]=1;
        bool ans= (dfs(i+1,j,n+1,vis,board,word) ||dfs(i,j+1,n+1,vis,board,word)||
        dfs(i-1,j,n+1,vis,board,word)||dfs(i,j-1,n+1,vis,board,word));
        vis[i][j]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        if(word=="")return false;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
            vector<vector<int>> vis(row,vector<int>(col,0));
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,vis,board,word))return true;                    
                }
            }
        }
        return false;
    }
};
