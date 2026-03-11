class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqs;
        unordered_map<char, int> freqt;

        if(s.length() != t.length()) return false;

        for(int i=0; i<s.length(); i++){
            freqs[s[i]]++;
            freqt[t[i]]++;
        }

        return freqs==freqt;
    }
};