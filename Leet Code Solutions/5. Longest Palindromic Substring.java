class Solution {
    public boolean check(String s, int i, int j){
        while(i<j){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
    public String longestPalindrome(String s) {
        int n = s.length();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substring(starting_index, starting_index+max_len);
    }
}
