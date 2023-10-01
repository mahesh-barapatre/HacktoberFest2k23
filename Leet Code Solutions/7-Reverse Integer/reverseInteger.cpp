class Solution {
public:
    int reverse(int x) {
        long reverse=0;
        while(x!=0){
            int lastdigit=x%10;
            x=x/10;
            reverse=reverse*10+lastdigit;
        }
        if(reverse<-2147483648 || reverse>2147483647){
            return 0;
        }
        else{
        return reverse;}
    }
};