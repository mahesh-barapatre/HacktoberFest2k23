class Solution {
public:
    void recursion(vector<int> num, int i, int n, vector<vector<int> > &result) {
        if(i == n-1){
            result.push_back(num);
            return;
        }

        for(int k = i; k < n; k++){
            if(k != i && num[k] == num[i]) continue;

            swap(num[k], num[i]);
            recursion(num, i+1, n, result);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());

        int n = num.size();

        vector<vector<int>> result;
        recursion(num, 0, n, result);
        
        return result;
    }
};
