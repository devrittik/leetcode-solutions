class Solution {
public:
    vector<string> ans;

    void helper(int& n, int& open, int& close, string& output) {
        
        if (!open && !close) {
            ans.emplace_back(output);
            return;
        }

        //include open
        if(open){
            output.push_back('(');
            helper(n, --open, close, output);
            ++open;
            output.pop_back();
        }

        //include close
        if(close > open){
            output.push_back(')');
            helper(n, open, --close, output);
            ++close;
            output.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        string output = "";
        helper(n, open, close, output);
        return ans;
    }
};