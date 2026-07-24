class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        for(char c:s){
            if(c == ' '){
                words.push_back(word);
                word="";
            }
            else{
                word+=c;
            }
        }
        words.push_back(word);

        if(words.size()!=pattern.size())
            return false;
        unordered_map<char,string>charToWord;
        unordered_map<string,char>wordToChar;
        for(int i=0;i<pattern.size();i++){
            char ch =pattern[i];
            string w =words[i];
           if(charToWord.count(ch) && wordToChar.count(w)){
                if(charToWord[ch] != w || wordToChar[w] != ch)
                    return false;
            } 
            else if(charToWord.count(ch) || wordToChar.count(w)){
                return false;
            }
             else{
                charToWord[ch] = w;
                wordToChar[w] = ch;
            }
        }
        return true;
    }
};