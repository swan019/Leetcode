class Solution {
public:
    char findTheDifference(string s, string t) {
        

        char xr = '\0';
        for(char ch : s){
            xr = xr ^ ch;
        }

        for(char ch : t){
            xr = xr ^ ch;
        }

        return xr;

        // vector<int> hash1(26, 0) , hash2(26,0);
        // for(auto ch : s){
        //     hash1[ch-'a']++;
        // }
        // for(auto ch : t){
        //     hash2[ch-'a']++;
        // }
        // char ans;
        // for(int i = 0; i < 26; ++i){
        //     if(hash1[i] != hash2[i]){
        //         ans = 'a' + i;
        //         break; 
        //     }
        // }
        
        // return ans;

        // return ' '; 
    }

};