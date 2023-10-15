class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream temp(preorder);
        string curr;
        int node = 1;
        while(getline(temp, curr, ',')){
            node--;
            if(node < 0) return false;
            if(curr != "#") node += 2;
        }

        return  node == 0;
    }
};