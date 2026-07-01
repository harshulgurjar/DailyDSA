class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int sum = 0;

        while (!q.empty()) {
            int n = q.size();
            sum = 0;   // Reset for current level

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return sum;
    }
};