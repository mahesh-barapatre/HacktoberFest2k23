class Solution {
public:

int solvetab(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>>curr(2,vector<int>(3,0));
    vector<vector<int>>next(2,vector<int>(3,0));


    for(int index=n-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int limit=1;limit<=2;limit++)
            {
                int profit=0;
            if(buy==1)
            {
                profit=max(-prices[index]+next[0][limit] , 0 + next[1][limit]); 
            }
            else
            {
                profit=max(prices[index]+ next[1][limit-1], 0 + next[0][limit]); 
            }
            curr[buy][limit]=profit;
            }
            next=curr;
        }

    }
    return next[1][2];
}

    int maxProfit(vector<int>& prices)
    {
        return solvetab(prices); 
    }
};
