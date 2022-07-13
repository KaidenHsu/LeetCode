// 7/13/22
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;

        for(int i = 0; i < haystack.length(); i++)
            for(int j = 0; j < needle.length() && i + j < haystack.length(); j++)
                if(haystack[i + j] != needle[j]) break;
                else if(j == needle.length() - 1) return i;
        
        return -1;
    }
};