// 7/10/22
class Solution {
public:
    int fib(int n) {
        int table[31] = {0, 1};
        for(int i = 2; i <= 30; i++) table[i] = table[i - 1] + table[i - 2];
        
        return table[n];
    }
};