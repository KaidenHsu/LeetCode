// 7/16/22
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        
        for(int i = s.size() - 1; i >= 0; --i){
            if(s[i] == ' ' && ans > 0) return ans;
            if(s[i] != ' ') ans++;
        }
        
        return ans;
    }
};