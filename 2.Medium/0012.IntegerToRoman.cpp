// 6/20/23

class Solution {
public:
    string intToRoman(int num) {
        string ans;

        // thousands digit
        for (int i = 0; i < num/1000; i++) ans += "M";

        int digit;

        // hundreds digit
        digit = num / 100;
        digit %= 10;

        switch (digit) {
            case 4:
                ans += "CD";
                break;
            case 5:
                ans += "D";
                break;
            case 6:
                ans += "DC";
                break;
            case 7:
                ans += "DCC";
                break;
            case 8:
                ans += "DCCC";
                break;
            case 9:
                ans += "CM";
                break;
            default:
                for (int i = 0; i < digit; i++)
                    ans += "C";
        }

        // tens digit
        digit = num / 10;
        digit %= 10;

        switch (digit) {
            case 4:
                ans += "XL";
                break;
            case 5:
                ans += "L";
                break;
            case 6:
                ans += "LX";
                break;
            case 7:
                ans += "LXX";
                break;
            case 8:
                ans += "LXXX";
                break;
            case 9:
                ans += "XC";
                break;
            default:
                for (int i = 0; i < digit; i++)
                    ans += "X";
        }

        // units digit
        digit = num % 10;

        switch (digit) {
            case 4:
                ans += "IV";
                break;
            case 5:
                ans += "V";
                break;
            case 6:
                ans += "VI";
                break;
            case 7:
                ans += "VII";
                break;
            case 8:
                ans += "VIII";
                break;
            case 9:
                ans += "IX";
                break;
            default:
                for (int i = 0; i < digit; i++)
                    ans += "I";
        }

        return ans;
    }
};
