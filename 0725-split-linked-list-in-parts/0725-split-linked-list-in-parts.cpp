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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL){
            curr = curr -> next;
            len++;
        }

        int partSize = len / k, extraNodes = len % k;
        vector<ListNode*> ans;
        curr = head;
        ListNode* prev = NULL;

        while(head){
            int eachPartSize = partSize;
            ans.push_back(curr);
            while(eachPartSize > 0){
                prev = curr;
                curr = curr -> next;
                eachPartSize--;
            }
            if(extraNodes != 0 && curr != NULL){
                extraNodes--;
                prev = curr;
                curr = curr -> next;
            }
            if(prev != NULL){
                head = curr;
                prev -> next = NULL;
            }
        }
        while(ans.size() != k)
            ans.push_back(NULL);
        
        return ans;
    }
};