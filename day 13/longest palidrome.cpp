class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        int len = 0;
        bool oddFound = false;

        for (auto it : mp) {
            if (it.second % 2 == 0) {
                len += it.second;
            } else {
                len += it.second - 1;
                oddFound = true;
            }
        }

        if (oddFound) len += 1;

        return len;
    }
};