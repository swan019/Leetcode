// class Solution {
// public:
//     void toChekIssqr(vector<int>& arr, int x, map<int, set<pair<int, int>>>& mp){

//         for(int i = 0; i < arr.size(); ++i){
//             long long m = arr[i]*arr[i];
//             if(m == x){
//                 mp[x].insert({arr[i],arr[i]});
//                 break;
//             }else if(m > x){
//                 break;
//             }
//         }

//     }

//     void toCheakPair(vector<int>& arr, int l ,map<int, set<pair<int, int>>>& mp,  map<int, int> & help){
//         int y;
//         int x;
//         for(int i = 0; i < arr.size(); ++i){
//             if( (l % arr[i] == 0 && help.find(l/arr[i]) != help.end())){
//                 x = l/arr[i];
//                 y = arr[i];
//                 if(y > x){
//                     swap(x,y);
//                 }

//                 // long long  X = x*y; 
//                 // if(X == l){
//                 //     mp[l].insert({x,y});
//                 // }

//                 mp[l].insert({x,y});
//             }else{
//                 mp[l].insert({});
//             }
//         }
//     }
//     int numFactoredBinaryTrees(vector<int>& arr) {

//         map<int, set<pair<int, int>>> mp;
//         map<int, int> help;
//         long long ans = 0;

//         for(int i = 0; i < arr.size(); ++i){
//             help[arr[i]] = i;
//         }

//         for(int i = 0; i < arr.size(); ++i){
//             toChekIssqr(arr, arr[i], mp);
//             toCheakPair(arr, arr[i], mp, help);
//         }

//         map<int,int> count;


//         for(auto it : mp){
//         //     cout << it.first << " -> ";
//         //     for(auto itr : it.second){
//         //         cout << "(" << itr.first << "," << itr.second << "), ";
//         //     }
//         //    cout << endl;

//             if(it.second.size() != 0){
//                 for(auto itr : it.second){
//                     if(itr.first == itr.second){
//                         count[itr.first] = 1;
//                         if(mp[itr.first].size() != 0){

//                         }
//                     }
//                 }
//             }

//         }

        


//         return ans;


//     }
// };

// class Solution {
// public:
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         int mod = static_cast<int>(1e9 + 7);
//         std::sort(arr.begin(), arr.end());
//         int ans = 0;
//         std::unordered_map<int, long> map;

//         for (int x : arr) {
//             long ways = 1;
//             int max = static_cast<int>(std::sqrt(x));

//             for (int j = 0, left = arr[0]; left <= max; left = arr[++j]) {
//                 if (x % left != 0) continue;
//                 int right = x / left;
//                 if (map.find(right) != map.end()) {
//                     ways = (ways + map[left] * map[right] * (left == right ? 1 : 2)) % mod;
//                 }
//             }
//             map[x] = ways;
//             ans = (ans + static_cast<int>(ways)) % mod;
//         }
//         return ans;
//     }
// };


class Solution {
const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        // Step 1: Sort the input array.
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Create a set to store unique numbers in the array.
        std::unordered_set<int> uniqueNumbers(arr.begin(), arr.end());
        
        // Step 3: Initialize a dynamic programming map.
        std::unordered_map<int, int> dp;
        for (int num : arr) {
            dp[num] = 1;
        }
        
        // Step 4: Dynamic Programming
        for (int i : arr) {
            for (int j : arr) {
                // If j is larger than the square root of i, break the loop because further j values won't be factors.
                if (j > std::sqrt(i)) break;
                
                // Check if j is a factor of i and if i/j is in the set of unique numbers.
                if (i % j == 0 && uniqueNumbers.find(i / j) != uniqueNumbers.end()) {
                    long long temp = static_cast<long long>(dp[j]) * dp[i / j];
                    
                    // Update the number of binary trees ending with i based on the factors j and i/j.
                    if (i / j == j) {
                        dp[i] = (dp[i] + temp) % MOD;
                    } else {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }
        
        // Step 5: Calculate the final result.
        int result = 0;
        for (auto& [_, val] : dp) {
            result = (result + val) % MOD;
        }
        return result;
    }
};