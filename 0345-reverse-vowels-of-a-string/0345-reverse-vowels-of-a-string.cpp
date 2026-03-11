class Solution {
public:
    bool isVowel(char c){
        char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

        for(char el : vowels){
            if(c==el || c==(el-32)){
                return true;
            }
        }

        return false;
    }

    string reverseVowels(string s) {
        int i=0, j=s.length()-1;

        while(i<=j){
            if(!isVowel(s[i])){
                i++;
                continue;
            }
            if(!isVowel(s[j])){
                j--;
                continue;
            }

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};