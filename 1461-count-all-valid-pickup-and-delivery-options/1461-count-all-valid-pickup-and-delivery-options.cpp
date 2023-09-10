class Solution {
public:
    long long int MOD = 1e9+7;
    int countOrders(int n) {
        long long int ANS = 1;
        for(long long int i=1; i<n; i++){
            ANS  = (ANS*((2*i*i)%MOD + (3*i)%MOD + 1))%MOD;
        }
        return ANS%MOD;
    }
};