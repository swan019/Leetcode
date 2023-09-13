class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        bool flag = false;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '6'){
                s[i] = '9';
                flag = true;
                break;
            }
        }
        // if(!flag){
        //     s[s.length() -1] = '6';
        // }

        int ans = stoi(s);
        return ans;
    }
};