class Solution {
public:
    bool isPalindrome(int number) {
        if (number < 0) return false;

        long long int reversedNumber = 0;
        long long int originalNumber = number;

        while (originalNumber > 0) {
            int lastDigit = originalNumber % 10;
            originalNumber /= 10;
            reversedNumber = reversedNumber * 10 + lastDigit;
        }

        return reversedNumber == (long long int)number;
    }

    
};