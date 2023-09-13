class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == 'L') balance++;
            else balance--;

            if(balance == 0)
                ans++;

        }

        return ans;
    }
};