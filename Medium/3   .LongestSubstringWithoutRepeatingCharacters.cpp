#define MAX(a, b) ((a) > (b)? (a) : (b))

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    char mem[128];
    int max = 0, ans;

     for(int i = 0; i < s.length(); i++){
        ans = 0;
        for (int j = 0; j < 128; ++j) mem[j] = 0;

        for(int j = i; j < s.length(); j++) {
           if(mem[s[j]] == 0){
               mem[s[j]] = 1;
               ans++;
           }else if(mem[s[j]] == 1){
               break;
           }
        }

        max = MAX(ans, max);
     }

    return max;
  }
};