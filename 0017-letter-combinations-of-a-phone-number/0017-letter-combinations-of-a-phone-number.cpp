class Solution {
public:
    unordered_map<char, string> keypad = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    void helper(string& digits, int& n, int& i, string& output, vector<string>& answer){

        if(i >= n) {
            answer.emplace_back(output);
            return;
        }

        string curr = keypad[digits[i]];

        for(int idx = 0; idx < curr.length(); idx++){
            output.push_back(curr[idx]);
            helper(digits, n, ++i, output, answer);
            --i;
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string output = "";
        int n = digits.length(), i=0;
        vector<string> answer;
        helper(digits, n, i, output, answer);
        return answer;
    }
};