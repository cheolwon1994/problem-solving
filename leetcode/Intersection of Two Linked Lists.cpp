class Solution {
public:

    int findLen(ListNode *node){
        int len = 0;
        while(node!=nullptr){
            len++;
            node = node->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node = headA;
        int aLen = findLen(node);
        node = headB;
        int bLen = findLen(node);

        while(aLen > bLen){
            aLen--;
            headA = headA->next;
        }
        while(bLen > aLen){
            bLen--;
            headB = headB->next;
        }

        while(aLen-- > 0){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
