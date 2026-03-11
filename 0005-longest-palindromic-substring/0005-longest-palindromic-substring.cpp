class Solution {
public:
    string expand(string& s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }

        left++, right--;

        return s.substr(left, (right-left+1));
    }

    string longestPalindrome(string s) {
        string ans, tempOdd, tempEven;

        for(int i=0; i<s.length(); i++){
            tempOdd = expand(s,i,i);
            ans = ans.length()>tempOdd.length() ? ans : tempOdd;
            tempEven = expand(s,i,i+1);
            ans = ans.length()>tempEven.length() ? ans : tempEven;
        }

        return ans;
    }
};