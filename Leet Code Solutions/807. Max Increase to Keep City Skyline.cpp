class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

      vector<int>maxRow;
      vector<int>maxCol;
      int maxi=0;
      int ans=0;

       for(int i=0;i<grid.size();i++) {
           for(int j=0;j<grid[0].size();j++) {
               maxi=max(maxi,grid[i][j]); }
               maxRow.push_back(maxi);
               maxi=0;
       }    

          for(int j=0;j<grid.size();j++) {
              for(int i=0;i<grid[0].size();i++){
                  maxi=max(maxi,grid[i][j]);}
                  maxCol.push_back(maxi);
                  maxi=0;
       } 

       for(int i=0;i<grid.size();i++) {
           for(int j=0;j<grid[0].size();j++) {
               int x=min(maxRow[i],maxCol[j]);
               if(x==grid[i][j])continue;
               ans+=(x-grid[i][j]); }
       }
       
    return ans;
    }
};
