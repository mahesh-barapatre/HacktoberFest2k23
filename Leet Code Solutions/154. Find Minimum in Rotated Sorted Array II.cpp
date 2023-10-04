class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int res = nums[0];
        while(l <= r){
            if(nums[l] < nums[r]){
                res = min(res, nums[l]);
                break;
            }
            int mid = (l + r) >> 1;
            cout << mid << " ";
            res = min(res, nums[mid]);
            if(nums[mid] > nums[l]){
                l = mid + 1;
            }
            else if(nums[mid] < nums[r]){
                r = mid-1;
            }
            else{
                if(nums[l] == nums[mid]){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
};
