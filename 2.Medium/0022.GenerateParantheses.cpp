// 7/11/22
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        if (n == 0) ans.push_back("");
        else for (int c = 0; c < n; ++c)
                for (string left: generateParenthesis(c))
                    for (string right: generateParenthesis(n - 1 - c))
                        ans.push_back("(" + left + ")" + right);
        
        return ans;
    }
};