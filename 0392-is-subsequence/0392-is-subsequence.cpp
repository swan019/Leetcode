class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length() < s.length()) return 0;

        int j = 0;
        for(int i = 0; i < t.length(); ++i){

            if(t[i] == s[j]){
                j++;
            }

        }

        if(j == s.length()){
            return true;
        }
        return false;
    }
};