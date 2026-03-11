class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        int partLen = part.length();

        while(pos != string::npos){
            s.erase(pos, partLen);
            pos = s.find(part);
        }

        return s;
    }
};