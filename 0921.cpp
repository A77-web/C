class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*pre=NULL,*cur=head;
        while(cur!=NULL)
        {
            ListNode*tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};
