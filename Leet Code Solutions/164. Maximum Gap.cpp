class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1;i++){
            int maxi = 0;
            maxi = nums[i+1]-nums[i];

            if(maxi>ans){
                ans = maxi;
            }
        }
        return ans;
    }
};
