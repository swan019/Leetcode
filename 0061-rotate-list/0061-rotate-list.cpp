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
private:
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* temp;
        while(curr != NULL){
            temp = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
    int len(ListNode* head){
        ListNode* temp = head;
        int i = 0;
        while(temp != NULL){
            i++;
            temp = temp -> next;
        }
        return i;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* dummy1 = new ListNode(-101);
        ListNode* dummy2 = new ListNode(-101);
        k = k % len(head);
        int first = len(head) - k;

        if(k == 0){
            return (head);
        }

        ListNode* pnt1 = dummy1;
        ListNode* pnt2 = dummy2;
        ListNode* point_Head = head;
        int i = 0;
        while(i < first && point_Head != NULL){
            ListNode* newNode = new ListNode(point_Head->val); point_Head = point_Head -> next;
            pnt1 -> next = newNode;
            pnt1 = pnt1 -> next;
            i++;
        }
        pnt1 -> next = NULL;
        while(point_Head != NULL){
            ListNode* newNode = new ListNode(point_Head->val); point_Head = point_Head -> next;
            pnt2 -> next = newNode;
            pnt2 = pnt2 -> next;
        }
        pnt2 -> next = NULL;

        dummy1 = reverse(dummy1 -> next);
        dummy2 = reverse(dummy2 -> next);

        pnt1 = dummy1;
        while(pnt1 -> next != NULL){
            pnt1 = pnt1 -> next;
        }

        pnt1 -> next = dummy2;

        return reverse(dummy1);
    }
};