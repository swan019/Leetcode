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
    int len(ListNode* head){
        ListNode* temp = head;
        int i = 0;
        while(temp != NULL){
            temp = temp -> next;
            i++;
        }
        return i;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == NULL) return NULL;
        int l = len(head) - n ;
        if(l == 0) return head -> next;
        ListNode* curr = head;
        ListNode* pre = NULL;
        for(int i = 0; i < l; ++i){
            pre = curr;
            curr = curr -> next;
        }

        if(pre != NULL && pre -> next != NULL){
            pre -> next = curr -> next;
        }

        return head;


    }
};