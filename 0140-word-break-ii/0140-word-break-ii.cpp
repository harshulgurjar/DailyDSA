class Solution {
public:
    vector<string>ans;

    void backtrack(int index,string &s,unordered_set<string> &st,vector<string>&path){
        if(index == s.size()){
            string sentence ="";
            for(int i=0;i<path.size();i++){
                sentence+=path[i];
                if(i!=path.size()-1)
                    sentence+=" ";
            }
            ans.push_back(sentence);
            return ;
        }
        string temp="";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(st.count(temp)){
                path.push_back(temp);
                backtrack(i+1,s,st,path);
                path.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<string>path;
        backtrack(0,s,st,path);
        return ans;
    }
};