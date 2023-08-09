// 8/9/23

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);
        dp[0]=1;
        if(s[0]=='0')dp[1]=0;
        else dp[1]=1;
        for(int i=2;i<=s.size();i++){
            int way1,way2;
            if(s[i-1]=='0')way1=0;
            else way1=dp[i-1];
            if(stoi(s.substr(i-2,2))<=26&&stoi(s.substr(i-2,2))>0&&s[i-2]!='0')way2=dp[i-2];
            else way2=0;
            dp[i]=way1+way2;
        }
        return dp[s.size()];
    }
};

