// 7/10/22
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26, 0);
        
        for(char c: magazine) v[c - 'a']++;
        
        for(char c: ransomNote){
            if(v[c-'a'] == 0) return false;
            else v[c-'a']--;
        }
        
        return true;
    }
};