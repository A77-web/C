class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && k > 0) {
            fast = fast->next;
            k--;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
