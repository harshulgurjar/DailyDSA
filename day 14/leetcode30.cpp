class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};

        unordered_map<string, int> freq;
        for (string &word : words) freq[word]++;

        int wordSize = words[0].size();
        int wordCount = words.size();
        int windowSize = wordSize * wordCount;
        int n = s.size();

        vector<int> ans;

        // Try all offsets
        for (int i = 0; i < wordSize; i++) {
            unordered_map<string, int> curr;
            int left = i, count = 0;

            for (int right = i; right + wordSize <= n; right += wordSize) {
                string word = s.substr(right, wordSize);

                // If word is valid
                if (freq.count(word)) {
                    curr[word]++;
                    count++;

                    // If word exceeds frequency → shrink window
                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }

                    // If all words matched
                    if (count == wordCount) {
                        ans.push_back(left);

                        // Move left forward
                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }
                } 
                else {
                    // Reset window
                    curr.clear();
                    count = 0;
                    left = right + wordSize;
                }
            }
        }

        return ans;
    }
};