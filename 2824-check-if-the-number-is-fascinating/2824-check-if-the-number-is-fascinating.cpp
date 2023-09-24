class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n);
        s += to_string(2*n);
        s += to_string(3*n);

        map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        cout << s << endl;

        if(mp.find('0') != mp.end()) return false;
        int sum = 0;
        for(auto it : mp){
            if(it.second > 1) return false;
            sum += ( it.first - '0');
        }

        if(mp.size() != 9) return false;

        if(sum == 45) return true;

        return false;
    }
};