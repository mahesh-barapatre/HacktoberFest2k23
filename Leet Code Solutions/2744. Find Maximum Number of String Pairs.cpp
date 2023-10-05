class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int pairs = 0;

        for (const string& word : words) {
            string reversed = word;
            reverse(reversed.begin(), reversed.end());

            if (wordCount.count(reversed) > 0 && wordCount[reversed] > 0) {
                pairs++;
                wordCount[reversed]--;
            } else {
                wordCount[word]++;
            }
        }

        return pairs;
    }
};