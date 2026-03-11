class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==0) return 0;
        int ans=0, flag=0;
        int freq[58]={};

        for(char& c : s){
            freq[c-'A']++;
        }

        for(int& el : freq){
            if(el>0){
                if(el%2==1 && flag==0) flag=1;
                ans+=(el-el%2);
            }
        }

        ans+=flag;

        return ans;
    }
};