class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int alic = 0, bob = 0;
        for(int i = 1; i < n-1; ++i){
            if(colors[i-1] == colors[i] &&  colors[i] == colors[i+1]){
                if(colors[i] == 'A'){
                    alic++;
                }else{
                    bob++;
                }
            }
        }

        return (alic - bob) >= 1;
    }
};