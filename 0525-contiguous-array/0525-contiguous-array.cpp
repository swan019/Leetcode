class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        //first approch
        // int maxi = 0;
        // int n = nums.size();
        // int i,j;
        // for( i = 0; i < n; ++i){
        //     int cnt1 = 0;
        //     int cnt0 = 0;
        //     for( j = i; j < n; ++j){
        //         if(nums[j] == 1){
        //             cnt1++;
        //         }else{
        //             cnt0++;
        //         }

        //         if(cnt1 == cnt0){
        //             maxi = max(maxi, j - i + 1);
        //         }
        //     }

        // }

        // return maxi;
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                sum += nums[i];
            }else{
                sum += (-1);
            }
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }else{
                mp[sum] = i;
            }

        }

        return maxi;


    }


};