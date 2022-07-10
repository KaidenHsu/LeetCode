// 7/10/22
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else if(s[i] == ')'){
                if(stk.empty()) return false;
                else if(stk.top() == '(') stk.pop();
                else break;              
            }else if(s[i] == ']'){
                if(stk.empty()) return false;
                else if(stk.top() == '[') stk.pop();
                else break;            
            }else if(s[i] == '}'){
                if(stk.empty()) return false;
                else if(stk.top() == '{') stk.pop(); 
                else break;
            }
        }

        
        return stk.empty();
    }
};