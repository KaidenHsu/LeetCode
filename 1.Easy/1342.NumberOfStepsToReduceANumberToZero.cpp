// 7/10/22
class Solution {
public:
    int numberOfSteps(int num) {
        short steps = 0;
        
        while(num > 0){
            if((num & 1) == 0) num >>= 1;
            else num--;
            
            steps++;
        }
        
        return steps;
    }
};