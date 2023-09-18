class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int bal = 0;
        int dafficiat = 0;
        for(int i = 0; i < gas.size(); ++i){
            bal += gas[i] - cost[i];
            if(bal < 0){
                dafficiat += abs(bal);
                start = i + 1;
                bal = 0;
            }
        }

        if(bal >= dafficiat){
            return start;
        }
        else{
            return -1;
        }
    }
};