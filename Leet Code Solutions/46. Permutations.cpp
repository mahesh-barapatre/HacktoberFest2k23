class Solution {
public:
    int n;  
    vector<vector<int>> ans;
    void f(int i, vector<int>& nums){
        if (i==n) {
            ans.push_back(nums);
            return ;
        } 
        f(i+1, nums);
        for (int j=i+1; j<n; j++){
            swap(nums[i], nums[j]);
            f(i+1, nums);
            swap(nums[i], nums[j]);
        }
    }    
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        f(0, nums);
        return ans;
    }
};
