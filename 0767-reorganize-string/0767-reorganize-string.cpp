class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {};

        for (char& c : s) {
            hash[c - 'a']++;
        }

        int max_freq = INT_MIN;
        char max_freq_char = 0;

        for (int i = 0; i < 26; i++) {
            if (hash[i] > max_freq) {
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }

            if (max_freq > (s.length() / 2 + s.length() % 2))
                return "";
        }

        int index = 0;
        
        while (max_freq>0) {
            s[index]=max_freq_char;
            max_freq--;
            index+=2;
        }
        
        hash[max_freq_char-'a']=0;

        for (int i = 0; i < 26; i++) {
            while (hash[i] > 0) {
                index = index >= s.length() ? 1 : index;
                s[index] = i + 'a';
                index += 2;
                hash[i]--;
            }
        }

        return s;
    }
};