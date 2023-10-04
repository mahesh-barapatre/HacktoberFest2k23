class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        double a=points[0][0]; double b=points[0][1];
      int n=points.size();  
        int ans=1;
       for(int i=0;i<n;i++){
           int a=points[i][0]; int b=points[i][1];   map<double,int>mp;int ct=0;
           for(int j=0;j<n;j++){
               if(i==j){continue;}
             int x=points[j][0]; int y=points[j][1];
              if(x-a==0){ct++; continue;}
             double slope=(double)(y-b)/(double)(x-a);
             mp[slope]++; 
           }
           for(auto x:mp){
               ans=max(ans,x.second+1);
           }
           ans=max(ans,ct+1);
             
       }
       return ans;

        
    }
};
