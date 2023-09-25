class NumArray {
public:
    long long prifix[100002];
    int n;
    NumArray(vector<int>& nums) {
        //  prifix[0] = nums[i];
        prifix[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            prifix[i] = prifix[i-1] + nums[i];
        }
        n = nums.size();
    }

    
    int sumRange(int left, int right) {
        // for(int i = 0; i < n; ++i){
        //     cout << prifix[i] << " ";
        // }
        // cout << endl;
        long long ans;
        if(left > 0){
            ans = prifix[right] - prifix[left-1];
        }else{
            ans = prifix[right];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */