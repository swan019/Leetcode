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
    ListNode* Reverse(ListNode* curr, ListNode* pre){
        if(curr == NULL){
            return pre;
        }
        ListNode* newNode = curr -> next;
        curr -> next = pre;
        return Reverse(newNode, curr);
    }
    ListNode* addTwoNumbers(ListNode* L1, ListNode* L2) {
        if(L1 == NULL) return L2;
        if(L2 == NULL) return L1;

        ListNode* l1 = Reverse(L1, NULL);
        ListNode* l2 = Reverse(L2, NULL);

        ListNode* dummy = new ListNode(-1000);
        ListNode* head = dummy;
        int carry = 0;
        while(l1 || l2){
            int sum = 0;
            if(l1 && l2){
                sum = carry + l1 -> val + l2 -> val;
            } else if(l1){
                sum = carry + l1 -> val;
            }else {
                sum = carry + l2 -> val;
            }

            carry = sum / 10;
            int val = sum % 10;

            ListNode* newNode = new ListNode(val);
            dummy -> next = newNode;
            dummy = dummy -> next;
            if(l1){
                l1 = l1 -> next;
            }

            if(l2){
                l2 = l2 -> next;
            }
        }

        if(carry > 0){
            ListNode* newNode = new ListNode(carry);
            dummy -> next = newNode;
            dummy = dummy -> next;
        }
        ListNode* ans = Reverse(head->next, NULL);
        return ans;

        
    }
};