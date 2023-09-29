class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pri(arr.size(), 0);
        pri[0] = arr[0];
        for(int i = 1; i < arr.size(); ++i){
            pri[i] = pri[i-1] + arr[i-1];
        }

        int sum = 0;
        for(int i = 0; i < n; ++i){
            int currsum = 0;
            for(int j = i; j < n; ++j){
                    // if((j-i + 1) % 2 != 0){
                    //     for(int k = i; k <= j; ++k){
                    //         sum += arr[k];
                    //     }
                    //   }

                    currsum += arr[j];

                    if((j-i + 1) % 2 != 0){
                        sum += currsum;
                    }else{
                        sum += 0;
                    }
            }
        }

        return sum;
    }
};