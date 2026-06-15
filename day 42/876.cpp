class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        vector<ListNode*> nodes;

        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        return nodes[nodes.size() / 2];
    }
};
