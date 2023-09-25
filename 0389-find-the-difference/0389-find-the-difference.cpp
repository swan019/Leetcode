class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> hash1(26, 0) , hash2(26,0);
        for(auto ch : s){
            hash1[ch-'a']++;
        }
        for(auto ch : t){
            hash2[ch-'a']++;
        }
        char ans;
        for(int i = 0; i < 26; ++i){
            if(hash1[i] != hash2[i]){
                ans = 'a' + i;
                break; 
            }
        }
        
        return ans;

        // return ' '; 
    }

};