class Solution {
public:
    bool isLetter(char c){
        if((c>='A' && c<='Z') || (c>='a' && c<='z')){
            return true;
        }else{
            return false;
        }
    }

    string reverseOnlyLetters(string s) {
        int i=0, j=s.length()-1;

        while(i<=j){

            if(!isLetter(s[i])){
                i++;
                continue;
            }
            if(!isLetter(s[j])){
                j--;
                continue;
            }

            swap(s[i],s[j]);

            i++;
            j--;
        }

        return s;
    }
};