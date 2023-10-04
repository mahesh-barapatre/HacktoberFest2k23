class Solution {
public:
       
    bool isavailable(string word,unordered_map<char,int>m){
        for(auto ele:word){
            if(m[ele]<1)return false;
            m[ele]--;
        }
        return true;
    }
    int func(int i,vector<string>&words,vector<int>&score,unordered_map<char,int>&m){
       
        if(i==words.size())return 0;
        
        int a=0,b=0;
        if(isavailable(words[i],m)){
            int sum=0;
            for(auto ele:words[i]){
                m[ele]--;
                sum+=score[ele-'a'];
            }
            a=sum+func(i+1,words,score,m);
            
            for(auto ele:words[i]){
                m[ele]++;
                sum+=score[ele-'a'];
            }
        }
        
        b=func(i+1,words,score,m);
        
        return max(a,b);
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        unordered_map<char,int>m;
        for(auto ele:letters){
            m[ele]++;
        }
        
        return func(0,words,score,m);
    }
};
