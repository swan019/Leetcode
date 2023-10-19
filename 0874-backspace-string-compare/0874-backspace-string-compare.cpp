class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st, st1;
        for(char ch : s){
            if(ch == '#' && !st.empty()){
                st.pop();
            }else if(ch != '#'){
                st.push(ch);
            }
        }

        for(char ch : t){
            if(ch == '#' && !st1.empty()){
                st1.pop();
            }else if(ch != '#'){
                st1.push(ch);
            }
        }
        
       string str1="";
       string str2="";

       while(!st.empty()){

           str1 += st.top();
           st.pop();

       }
       while(!st1.empty()){

           str2+=st1.top();
           st1.pop();

       }
        
        return str1 == str2;


        
    }
};