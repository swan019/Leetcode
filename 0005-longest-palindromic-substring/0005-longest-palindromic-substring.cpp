class Solution {
public:
    pair<int, int> Points_of_Palindrome(string s, int i, int j){
        int start = -1;
        int end = -1;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            start = i;
            end = j;
            i--;
            j++;
        }
    
        return pair<int,int>{start, end};
    }
    string longestPalindrome(string s) {
        int Maxi_Distance = INT_MIN;
        string Maxi_length = "";
        for(int i = 0; i < s.length(); ++i){
            pair<int, int> temp_odd = Points_of_Palindrome(s,i,i);
            pair<int, int> temp_even = Points_of_Palindrome(s,i,i+1);
            int odd_dist = temp_odd.second - temp_odd.first + 1;
            if(odd_dist > Maxi_Distance){
                Maxi_Distance = odd_dist;
                Maxi_length = s.substr(temp_odd.first, odd_dist);
            }
            int even_dist = temp_even.second - temp_even.first + 1;
            if(even_dist > Maxi_Distance){
                Maxi_Distance = even_dist;
                Maxi_length = s.substr(temp_even.first, even_dist);
            }
            
        }
        
        return Maxi_length;
    }
};