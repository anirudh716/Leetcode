class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr -> next;
            ListNode* prev = dummy;
            ListNode* next = dummy -> next;

            while(next != NULL){
                if(next -> val > curr -> val) break;
                prev = next;
                next = next -> next;
            }
            curr -> next = next;
            prev -> next = curr;
            curr = temp;
        }
        return dummy -> next;
    }
};