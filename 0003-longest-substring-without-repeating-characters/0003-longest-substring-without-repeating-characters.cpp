class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0;
        string prev=s.substr(0,1);
        string current=s.substr(0,0);
        int ans=0;
        while(j<s.length()){
            current=s.substr(i, j-i+1);
            for(int idx=i; idx<=j && j+1<s.length(); idx++){
                if(s[idx]==s[j+1]){
                    if(prev.length()<current.length()){
                     prev=current; 
                    }
                    i=idx+1;
                    break;
                }
            }
            
            j++;
        }

        ans=max(prev.length(), current.length());
        
        return ans;
    }
};