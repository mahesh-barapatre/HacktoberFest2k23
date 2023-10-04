class Solution {
public:

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> bloomTime;

        for(int i = 0; i < plantTime.size(); i++){
            bloomTime.push_back({growTime[i], plantTime[i]});
        }
        sort(bloomTime.begin(), bloomTime.end(), [](pair<int, int>& p1, pair<int, int>& p2){
            return p1.first == p2.first ? p1.second > p2.second : p1.first > p2.first;
        });

        int maxDayBloom = 0;
        int dayPassed = 0;
        for(pair<int,int> bloom : bloomTime){
            dayPassed += bloom.second;
            maxDayBloom = max (maxDayBloom, dayPassed + bloom.first);
        }
        return maxDayBloom;

    }
};
