class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>seen;
        for(char c:s){
            if(seen[c] == 1){
                return seen[c];
            }

            seen[c]++;
        }
        return -1;
    }
};