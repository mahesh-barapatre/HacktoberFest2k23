class Solution {
public:
    int search(vector<int>& nums, int target) {
         int size= nums.size();
    int l=0,r=size-1;
    
    while(l<=r){
         int mid;
         mid=(l+r)/2;
         if (nums[mid] == target) {
           return mid;
         }
          else if (nums[mid]>target){
                 r= mid-1;
         }
         else{
             l=mid+1;
         }
    }
    return -1;

    }
};