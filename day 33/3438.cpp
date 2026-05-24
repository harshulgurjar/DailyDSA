class Solution {
public:
    string findValidPair(string s) {
        map<char,int>freq;
        for(auto c:s){
            freq[c]++;
        }
        string ans ="";
        for(int i = 0; i < s.size()-1; i++){

            char a = s[i];
            char b = s[i+1];

            if(a != b &&
               freq[a] == a - '0' &&
               freq[b] == b - '0'){
                ans += a;
                ans += b;

                return ans;
            }}
        return ans;
    }
};
