class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>temp;
        for(int i=0; i<nums.size(); i++){
            int req=target-nums[i];
            if(temp.find(req)!=temp.end()){
                ans.push_back(temp[req]);
                ans.push_back(i);
                break;
            }
            temp.insert({nums[i],i});
        }
        return ans;
    }
};