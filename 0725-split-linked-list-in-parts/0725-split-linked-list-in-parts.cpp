class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        int size=0;
        for(ListNode* node=head;node;node=node->next) size++;
        int n=size/k, r=size%k;
        ListNode* node=head, *prev=NULL;
        for(int i=0;node && i<k;i++,r--){
            ans[i]=node;
            for(int j=0;j<n+(r>0);j++){
                prev=node;
                node=node->next;
            }
            prev->next=NULL;
        }
        return ans;
    }
};