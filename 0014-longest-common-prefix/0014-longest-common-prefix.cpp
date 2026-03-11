class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end(),
             [](const std::string& a, const std::string& b) {
                 return a.length() < b.length();
             });

        if(strs[0]==""){
            return "";
        }
        
        int len = strs.size();
        string prefix = strs[0];

        for (int i = 1; i < len; i++) {
            for(int j=0; j<prefix.length(); j++){
                if(prefix[j] != strs[i][j]){
                    prefix.erase(j);
                    break;
                }
            }
        }

        return prefix;
    }
};