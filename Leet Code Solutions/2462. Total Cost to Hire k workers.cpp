class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long int ans = 0;
        if ((costs.size() - 2 * candidates) + 1 <= k || candidates >= (costs.size() / 2 + costs.size() % 2))
        {
            sort(costs.begin(), costs.end());
            for (int i = 0; i < k; i++)
                ans += costs[i];
            return ans;
        }
        else
        {
            int cnt = 0;
            priority_queue<int, vector<int>, greater<int>> Left;
            priority_queue<int, vector<int>, greater<int>> Right;
            for (int left = 0, right = costs.size() - 1; cnt != k;)
            {
                if (Left.size() < candidates)
                {
                    Left.push(costs[left]);
                    left++;
                }
                if (Right.size() < candidates)
                {
                    Right.push(costs[right]);
                    right--;
                }

                if (Left.size() == candidates && Right.size() == candidates)
                {
                    ans += min(Left.top(), Right.top());
                    if (min(Left.top(), Right.top()) == Left.top())
                        Left.pop();
                    else
                        Right.pop();
                    cnt++;
                }
            }
            return ans;
        }
    }
};