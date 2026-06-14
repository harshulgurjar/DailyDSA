class Solution {
public:
    int pairSum(ListNode* head) {

        vector<int> nums;

        // store values
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = nums.size() - 1;

        int ans = 0;

        while (i < j) {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};
