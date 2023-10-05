class Solution {
public:

    void findCombi(int index,int target,vector<int>& arr,vector<vector<int>> &ans,vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index;i<arr.size();i++){
            if(i> index && arr[i] == arr[i-1]){
                continue;
            }

            if(arr[i] > target){
                break;
            }
            ds.push_back(arr[i]);
            findCombi(i + 1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombi(0,target,candidates,ans,ds);
        return ans;
       
    }
};
