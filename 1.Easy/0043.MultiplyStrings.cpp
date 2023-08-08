// 8/5/23

class Solution {
public:
    string multiply(string A, string B) {
        if(A=="0"||B=="0"){return "0";}
        int n = A.length(),m = B.length();
        string ans(n+m,'0');

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int num = (A[i] - '0') * (B[j] - '0') + ans[i+j+1] - '0';
                ans[i+j+1] = num%10 + '0';
                ans[i+j] += num/10;
            }
        }
        for(int i=0;i<ans.length();i++){
            if(ans[i] != '0'){ return ans.substr(i);}
        }
        return "0";
    }
}
