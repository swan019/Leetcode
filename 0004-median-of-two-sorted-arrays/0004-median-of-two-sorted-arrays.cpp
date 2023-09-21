class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        for(auto it : nums1){
            temp.push_back(it);
        }
        for(auto it : nums2){
            temp.push_back(it);
        }

        sort(temp.begin(), temp.end());
        int n = temp.size();
        if(n%2 != 0){
            return double(temp[n/2]);
        }
        n = n /2;

        double ans = (temp[n] + temp[n-1])/2.0;
        return double(ans);
    }
};