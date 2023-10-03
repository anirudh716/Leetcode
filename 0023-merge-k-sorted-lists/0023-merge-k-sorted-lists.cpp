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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return NULL;
        int left = 0;
        int right = lists.size()-1;
        while(right > 0){
            left = 0;
            while(left < right){
                lists[left] = mergeTwoLists(lists[left], lists[right]);
                left++;
                right--;
            }
        }
        return lists[0];
    }

    ListNode*  mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else{
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr -> next;
        }
        
        if(l1)  curr -> next = l1;
        else    curr -> next = l2;
        
        return dummy.next;
    }
};