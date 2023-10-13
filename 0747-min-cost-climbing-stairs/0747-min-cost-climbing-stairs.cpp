class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int ans = 0;
        // if(n < 3){
        //     sort(cost.begin(), cost.end());
        //     return cost[0];
        // }

        // int ptr;
        // if(cost[0] < cost[1]){
        //     ans = cost[0];
        //     ptr = 0;
        // }else{
        //     ans = cost[1];
        //     ptr = 1;
        // }

        // if(n == 3){
        //     if(cost[0] + cost[2] > cost[1]){
        //         return cost[1];
        //     }
        // }

        // cout << ans << " " << ptr << endl;

        // while(ptr < n-2){

        //     if(cost[ptr+1] < cost[ptr+2]){
        //         ans += cost[ptr+1];
        //         ptr += 1;
        //     }else{
        //         ans += cost[ptr+2];
        //         ptr += 2;
        //     }
        //     cout << ans << " " << ptr << endl;
        // }
        // return ans;

        cost.push_back(0);
        int n = cost.size();
        for(int i = n-3; i >= 0; i--){
            cost[i] += min(cost[i+1], cost[i+2]);
        }

        return min(cost[0], cost[1]);
    }
};