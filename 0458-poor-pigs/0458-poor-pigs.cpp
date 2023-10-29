class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int b = (minutesToTest /minutesToDie )+1;
        int ans = ceil(log2(buckets)/log2(b));
        return ans;
    }
};