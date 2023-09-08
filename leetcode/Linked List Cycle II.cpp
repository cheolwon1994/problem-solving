class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        bool isCycle = false;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle) return nullptr;

        while(head != slow){
            head = head->next;
            slow = slow->next;
        }

        return head;
    }
};
