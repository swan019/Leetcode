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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        if(head -> next -> next == NULL){
            head -> next = NULL;
        }

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        if(slow->next != NULL && slow->next->next != NULL){
            slow->val = (slow->next)->val;
            slow->next = slow->next->next;
        }else{
            if(slow -> next != NULL){
                slow -> val = slow -> next -> val;
                slow -> next = slow -> next -> next;
            }
        }

        cout << slow -> val << endl;
        

        

        

        return head;
    }
};