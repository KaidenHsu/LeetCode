class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for(int i = 1; i <= n; i++){
            string str = "";
            
            if(i % 3 == 0) str += "Fizz";
            if(i % 5 == 0) str += "Buzz";
            if(str.empty()) str += to_string(i);
            
            ans.push_back(str);
        }
        
        return ans;
    }
};