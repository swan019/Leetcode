/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int low = 0;
        int high = n-2;
        while(low < high){
            int mid = (low+high)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }

        int peak = low;

        // first line

        low = 0;
        high = peak;
        while(low < high){
            int mid = (low+high)/2;
            if(mountainArr.get(mid) < target){
                low = mid+1;
            }else{
                high = mid;
            }
        }

        if(mountainArr.get(low) == target){
            return low;
        }

        // second line

        low = peak+1;
        high = n-1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) > target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (mountainArr.get(low) == target) {
            return low;
        }
        return -1;
    }
};