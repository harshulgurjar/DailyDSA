class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }

            // Avoid leading zeroes
            if (st.empty() && digit == '0') {
                continue;
            }

            st.push(digit);
        }

        // If k is still remaining, remove digits from the end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        if (st.empty()) {
            return "0";
        }

        string result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result.empty() ? "0" : result;
    }
};