class Solution {
public:
    int expandStr(string s, int left, int right){
        int count=0;

        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int totalCount=0;

        for(int center=0; center<s.length(); center++){
            //Odd handle
            int oddCount = expandStr(s, center, center);
            totalCount+=oddCount;
            //Even handle
            int evenCount = expandStr(s, center, center+1);
            totalCount+=evenCount;
        }

        return totalCount;
    }
};