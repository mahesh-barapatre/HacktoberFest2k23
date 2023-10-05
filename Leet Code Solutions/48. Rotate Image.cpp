class Solution {
public:
    void rotate(vector<vector<int>>& v) 
    { int n=v.size();
      int m=v[0].size();
      for(int i=0;i<n;i++)
      {
          for(int j=i;j<m;j++)
          {
               swap(v[i][j],v[j][i]);
          }
          int l=0;
          int r=m-1;
          while(l<=r)
          {
              swap(v[i][l],v[i][r]);
              l++;
              r--;
          }
      }        
    }
};
