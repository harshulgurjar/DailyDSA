class Solution {
public:
    bool alpanum(char c){
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(!alpanum(s[l])){
                l++;
                continue;
            }
            if(!alpanum(s[r])){
                r--;
                continue;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            r--;
            l++;
        }
        return true;
    }
};