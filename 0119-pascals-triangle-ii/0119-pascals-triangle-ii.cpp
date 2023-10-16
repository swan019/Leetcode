class Solution {
public:
    vector<int> getRow(int n) {
    vector<int> temp;
    long long  ans = 1;
    n++;
    temp.push_back(1);
    for(int i =1; i < n; ++i){
        ans = ans * (n-i);
        ans /= i;
        temp.push_back(ans);
    }

    return temp;
    }
};