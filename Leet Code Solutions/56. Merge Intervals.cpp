class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
       vector<vector<int>>v;
       int start;
       int end;
       int i;
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0];
       });
       
       for( i=0;i<nums.size();i++)
       {
           int start=nums[i][0];
           int end=nums[i][1]; 
            while(i!=nums.size()-1 && end>=nums[i+1][0])
           {
               end= max(end,nums[i+1][1]);
               i++;
           }
           
           
           vector<int> temp={start,end};
           v.push_back(temp);
       } 
       return v;
    }
};
