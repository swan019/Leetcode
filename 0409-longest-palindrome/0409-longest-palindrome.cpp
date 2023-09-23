class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        if(mp.size() == 1){
            return s.length();
        }

        int cntLength = 0;
        for(auto it : mp){
           cntLength += it.second / 2 * 2;
           if(cntLength % 2 == 0 && it.second % 2 == 1){
               cntLength++;
           }
        }
        
        return cntLength;
    }
};