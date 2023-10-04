class Solution {
public:
    int helper(vector<int>& sat, int curr){
        if(curr==sat.size()) return 0; 
        int coeff=0;
        for(int i=curr;i<sat.size();++i){
            coeff+=sat[i]*(i-curr+1);
        }
        return max(coeff,helper(sat,curr+1));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return helper(satisfaction,0);
    }
};
