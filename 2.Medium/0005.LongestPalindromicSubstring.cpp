class Solution {
public:
    string longestPalindrome(string s) {
        unsigned short tmp1, tmp2, max = 1;
        string ans;

        for(int i = 0; i < s.length(); i++){
            tmp1 = 1, tmp2 = 0;

            for(int j = 0; i - j >= 0 && i + j < s.length(); j++){
                if(s[i - j] == s[i + j]) tmp1 += 2;
                else if(s[i - j] != s[i + j]) break;

                if(tmp1 > max){
                    ans = s.substr(i - j, 2 * j + 1);
                    max = tmp1;
                }
            }

            for(int j = 0; i - j >= 0 && i + j - 1 < s.length(); j++){
                if(s[i - j] == s[i + j - 1]) tmp2 += 2;
                else if(s[i - j] != s[i + j - 1]) break;

                if(tmp2 > max){
                    ans = s.substr(i - j, 2 * j);
                    max = tmp2;
                }
            }
        }

        return ans;
    }
};