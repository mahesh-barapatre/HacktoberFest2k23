class Solution {
public:
    long long putMarbles(vector<int>& v, int d) {
            long long int l1 = 0;
        
         long long int l2 = 0;
           d--;
        
         vector<long long int>res1;
        
          for(long long int i = 0;i<v.size()-1;i++){res1.push_back(v[i]+v[i+1]);}

        
             vector<long long int>res;
        
          for(long long int i = 0;i<v.size()-1;i++){res.push_back(v[i]+v[i+1]);}
        
         sort(res1.begin() , res1.end() , greater<long long int>());
          sort(res.begin() , res.end());
        
        
            for(long long int i =0;i<d;i++) l2 += res1[i];
        for(long long int i =0;i<d;i++) l1 += res[i];
        
        
        return (l2 - l1);
        
    }
};
