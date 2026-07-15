/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>ans;
    void dfs(TreeNode* root,int t,vector<int>& temp){
        if(root == nullptr){
            return;
        }
        temp.push_back(root->val);
        t-=root->val;
        if(root->left == nullptr && root-> right == nullptr){
            if(t == 0)
            ans.push_back(temp);
        }else{
            dfs(root->left,t,temp);
            dfs(root->right,t,temp);
        }
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        
        vector<int>temp;
        dfs(root,t,temp);
        return ans;
    }
};