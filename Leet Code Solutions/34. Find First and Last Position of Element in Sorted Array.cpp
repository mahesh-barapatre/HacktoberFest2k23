class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index=(upper_bound(nums.begin(),nums.end(),target)-nums.begin());
        int index1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int> ans;
        ans.push_back(index1);
       
       if(index1!=index){
           ans.push_back(index-1);
           return ans;

       }
       else return {-1,-1};
    }
};
