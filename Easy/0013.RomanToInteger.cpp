class Solution {
private:
    int convert(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        return 1000;
    }
    
public:
    int romanToInt(string s){
        int ans = convert(s.back());
        int i = s.length() - 2;
        
        while(i >= 0){
            if(convert(s[i]) < convert(s[i + 1])) ans -= convert(s[i]);
            else ans += convert(s[i]);
            i--;
        }
        
        return ans;
    }
};