class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
       
        int len = str1.length() - 1;
        for(int i = len; i >= 0; i--){
            char curr = str1[i];
            char forwd;
            if(curr == 'z'){
                forwd = 'a';
            }else{
                forwd = curr + 1;
            }

            int len = str2.length()-1;
            if(len == -1) return 1;
            if(curr == str2[len]){
                str2.erase(len, 1);
            }else if(forwd == str2[len]){
                str2.erase(len, 1);
            }
        }

        
        return !str2.size();
    }
};