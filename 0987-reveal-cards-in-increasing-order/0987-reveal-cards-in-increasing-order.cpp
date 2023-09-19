class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        vector<int> ans(deck.size());
        for(int i = 0; i < deck.size(); ++i){
            q.push(i);
        }
        sort(deck.begin(), deck.end());
        int pnt = 0;
        int cnt = 0;
        while(!q.empty()){
            if(cnt%2==0){
                ans[q.front()] = deck[pnt++];
                q.pop(); 
            }else{
                q.push(q.front());
                q.pop();
            }
            cnt++;
        }

        return ans;
    }
};