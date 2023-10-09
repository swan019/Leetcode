class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;

        bool flag = true;
        vector<int> ans;

        while(low < high){
            // if(low > high){
            //     break;
            // }
            int ck = numbers[low] + numbers[high];
            if(ck == target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;
            }

            if(ck > target){
                high--;
            }else{
                low++;
            }
        }

        return ans;

    }
};