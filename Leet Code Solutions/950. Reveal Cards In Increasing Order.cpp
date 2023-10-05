class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin() , deck.end());
        int n = deck.size();
        queue<int>q;
        int i = 0;
        while(i<n) q.push(i++);
        vector<int>ans(n);
        for(i = 0 ; i < n ; i++){
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};
