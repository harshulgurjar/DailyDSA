class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int originalmatrow=mat.size();
        int originalmatcoloum=mat[0].size();
        int totalelement=originalmatrow*originalmatcoloum;

        if(totalelement!=r*c){
            cout<<"reshaping not possible";
            return mat;
        }

        vector<vector<int>>reshape(r,vector<int>(c)) ;
         for(int i=0;i<totalelement;i++){
            reshape[i/c][i%c] = mat[i/originalmatcoloum][i%originalmatcoloum];

        }
        return reshape;

    }
};