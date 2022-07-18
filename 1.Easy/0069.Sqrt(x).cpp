// 7/18/22
class Solution {
public:
    int mySqrt(int x) {
        long long s = 0, e = x, ans, mid;
        
        while(s <= e){             
            mid = (s + e) / 2;
            
            if(mid * mid == x) return mid;
            else if(mid * mid < x){             
                s = mid + 1;
                ans = mid;
            }else e = mid - 1;
        }
        
        return ans;   
    }
};