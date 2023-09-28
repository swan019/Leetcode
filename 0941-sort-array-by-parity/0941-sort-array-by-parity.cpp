class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int i = 0;
        int j = 0;
        while(j < arr.size())
        {
            if(arr[j]&1==1)
            {
                j++;
            }else{
                swap(arr[i++], arr[j++]);

            }
        }

        return arr;
    }
};