class Solution {
public:
    void rev(vector<char>& s, int& start, int& end){

        // base case
        if(start >= end) return;
        // process
        swap(s[start], s[end]);
        // RE
        rev(s, ++start, --end);
    }

    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;
        rev(s, start, end);
    }
};