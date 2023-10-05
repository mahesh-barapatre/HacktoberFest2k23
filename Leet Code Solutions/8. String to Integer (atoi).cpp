class Solution {
public:
    int myAtoi(string s) {
        long int num=0;
        if(s.empty())
        {
            return 0;
        }
        int n=s.length(),i=0;
        bool sign=false;
        while(i<n&&s[i]==' ')
        {
            i++;
        }
        if(i==n)return 0;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-');
            i++;
        }
        while('0'<=s[i] && s[i]<='9'&&i<n)
        {
            num=(num*10);
            num=num+(s[i]-'0');
            if(num>=INT_MAX||num<=INT_MIN)
            break;
            i++;
        }
        if(sign)
        {
            num=num*(-1);
        }
        if(num>=INT_MAX)num=INT_MAX;
        if(num<=INT_MIN)num=INT_MIN;
        return num;
    }
};
