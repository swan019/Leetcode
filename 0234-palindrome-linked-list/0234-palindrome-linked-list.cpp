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
    ListNode* Middle(ListNode* head){
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        ListNode* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        ListNode* curr = head, *pre = NULL, *temp;
        while(curr != NULL){
            temp = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }

    bool compare(ListNode* l1 , ListNode* l2){
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val != l2 -> val) return false;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;
        if(head -> next == NULL) return true;
        ListNode* mid = Middle(head);
        ListNode* newNode = reverseList(mid -> next);
        mid -> next = NULL;
        return compare(head, newNode);
    }
};