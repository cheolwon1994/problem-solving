/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* start = head;
        //1. calculate length
        while(start != nullptr){
            start = start->next;
            len++;
        }
        if(head == nullptr || len == 1) return head;

        int idx = 0;
        start = head;
        //2. get k the remain by len
        k %= len;
        if(k==0) return head;
        
        ListNode* temp;
        //3. get the rotated start point
        while(++idx <= len - k){
            if(idx == len-k){
                temp = start->next;
                start->next = nullptr;
                break;
            }
            start = start -> next;
        }

        //4. add head to the end of temp
        ListNode* answer = temp;
        while(answer != nullptr){
            if(answer->next == nullptr) break;
            answer = answer->next;
        }
        answer->next = head;

        return temp;
    }
};