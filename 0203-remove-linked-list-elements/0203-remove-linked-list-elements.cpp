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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        while(head != NULL && head -> val == val ){
            head = head -> next;
        }
        ListNode* curr = head, * pre = NULL;
        while(curr != NULL){
            if(curr -> val != val){
                        pre = curr;
                         curr = curr -> next;
            }
            if(curr != NULL && curr -> val == val){
                while(curr != NULL && curr -> val == val ){
                        curr = curr -> next;
                }
                        if(curr != NULL){
                            pre -> next = curr;
                            pre = curr;
                            curr = curr -> next;
                        }else{
                            pre -> next = NULL;
                        }

                // if(curr != NULL && curr -> val == val)

            }

                
        }
        return head;
    }
};