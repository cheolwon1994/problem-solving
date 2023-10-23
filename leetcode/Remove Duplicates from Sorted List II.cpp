class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int preVal = -101;
        ListNode* start = new ListNode();
        ListNode* root = start;

        while(head!= nullptr){
            //if head->val == preVal
            if(head->val == preVal){
                head = head->next;
            }
            else{
                if(head->next != nullptr){
                    preVal = head->val;
                    
                    //another dup
                    if(head->next->val == head->val){
                        head = head->next->next;
                    }
                    else{
                        start->next = head;
                        start = start->next;
                        head = head->next;
                    }
                }
                //head is last node
                else{
                    start->next = head;
                    start = start->next;
                    head = head->next;
                }  
            }
        }
        start->next = nullptr;

        return root->next;
    }
};