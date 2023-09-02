class Solution {
public:
    double angleClock(int hour, int minutes) {
       
        double byHrs = hour*30;
        double byMin = minutes*5.5;
        double ans;
        if(byHrs > byMin) 
            ans = byHrs - byMin;
        
        if(ans < 0) ans *= (-1);
        
        if(ans > 180)  return 360-ans;
        return ans;
    }
};