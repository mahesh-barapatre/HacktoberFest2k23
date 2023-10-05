class Solution {
    public String longestPalindrome(String str) {
        int s=0, e=0;
        for(int i=0; i<str.length(); i++){
            int odd=pal(str,i,i);
            int even=pal(str,i,i+1);
            int len=Math.max(odd,even);

            if(len>e-s){
                s=i-(len-1)/2;
                e=i+len/2;
            }
        }
        return str.substring(s,e+1);
    }

    public int pal(String str, int s, int e){
        while(s>=0 && e<str.length() && str.charAt(s)==str.charAt(e)){
            s--;
            e++;
        }
        return e-s-1;
    }
}
