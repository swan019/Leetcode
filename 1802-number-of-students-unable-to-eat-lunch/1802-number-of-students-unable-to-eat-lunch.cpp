class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;
        for(int i = 0; i < students.size(); i++){
            st.push(sandwiches[sandwiches.size() - 1 - i]);
            q.push(students[i]);
        }

        int cnt_steps = 0;
        while(!q.empty()){
            if(st.top() == q.front()){
                st.pop(); 
                q.pop();
                cnt_steps = 0;
            }
            else{
                
                    int k = q.front();
                    q.pop();
                    q.push(k);
                    cnt_steps++;
            }
                if(cnt_steps == q.size()) break;
        }

        return q.size();
    }
};