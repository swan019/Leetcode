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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode* temp = head;
        while(temp != NULL){
            mp[temp -> val]++;
            temp = temp -> next;
        }

        ListNode* ans = new ListNode(-101);
        ListNode* ANS = ans;
        for(auto it : mp){
            if(it.second < 2){
                ListNode* st = new ListNode(it.first);
                ans -> next = st;
                ans = ans -> next;
            }
        }

        return ANS->next;
    }
};