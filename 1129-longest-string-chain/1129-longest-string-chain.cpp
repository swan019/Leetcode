class Solution {
public:
    static bool compare(string a, string b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        map<string, int> mp;
        int ans = 0;
        for(auto it : words){
            int longest = 0;
            for(int i = 0; i < it.length(); ++i){
            string temp = it;
                 temp.erase(i, 1);
                longest = max(longest, mp[temp]+1);
            }

            mp[it] = longest;
            ans = max(ans, longest);
        }

        return ans;
        
    }
};