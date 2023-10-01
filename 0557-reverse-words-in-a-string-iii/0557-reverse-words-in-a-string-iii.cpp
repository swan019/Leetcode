class Solution {
public:

    string reverseWords(string s) {
        vector<string> st;
        int ptr = 0 , i = 0;
        while(i < s.length()){
            //string temp = "";
            int cnt = 0;
            while(s[i] != ' ' && i < s.length()){
                cnt++;
                i++;
            }
            st.push_back(s.substr(ptr, cnt)+' ');
            i++;
            ptr = i;
        }
        string temp = "";
        for(auto it : st){
            reverse(it.begin(), it.end());
            temp += it;
        }
        temp = temp.substr(1, temp.length());
        return temp;

        
    }
};