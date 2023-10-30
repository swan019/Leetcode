class Solution {
public:
    static bool comp(int a, int b) {
      
        int bit_A = __builtin_popcount(a);
        int bit_B = __builtin_popcount(b);
        if (bit_A == bit_B) {
            return a < b;
        }
        return bit_A < bit_B;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};