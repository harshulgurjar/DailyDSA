class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 0;
        long long h = n;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long totalCoins = mid * (mid + 1) / 2;

            if (totalCoins == n) {
                return mid;
            }

            if (totalCoins < n) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return h;
    }
};