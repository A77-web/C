class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head,*pre=NULL;
        while(cur)
        {
            //用tmp保存cur的位置
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};
