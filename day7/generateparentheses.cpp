class Solution {
public:
    vector<string> res;
    void backtrack(int open,int close,string curr,int n){
            if(curr.length()==2*n){
                res.push_back(curr);
            }
            if(open<n){
                curr.push_back('(');
                backtrack(open+1,close,curr,n);
                curr.pop_back();
            }
            if(close<open){
                curr.push_back(')');
                backtrack(open,close+1,curr,n);
                curr.pop_back();
            }
        }
    vector<string> generateParenthesis(int n) {
        string curr="";
        backtrack(0,0,curr,n);
        return res;
    }
};