// 6/20/23
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        deque<string> dq;
        vector<string> ans;
        string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // edge cases
        if (digits == "") return ans;

        // generate valid combinations
        for (int i = 0; i < mapping[digits[0]-'2'].length(); i++) {
            dq.push_back(string(1, mapping[digits[0]-'2'][i]));
        }

        for (int i = 1; i < digits.length(); i++) {
            string pattern;
            while (dq.front().length() == i) {
                pattern = dq.front();
                dq.pop_front();

                for (int j = 0; j < mapping[digits[i]-'2'].length(); j++) {
                    dq.push_back(pattern + string(1, mapping[digits[i]-'2'][j]));
                }
            }

        }


        // copy the content in the deque into the ans vector
        deque<string>::iterator it;
        for (it = dq.begin(); it != dq.end(); it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};
