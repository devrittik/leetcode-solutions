class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> groups;
        string key;

        for(string& str : strs){
            key = str;
            sort(key.begin(),key.end());
            groups[key].emplace_back(str);
        }

        for(auto& entry : groups){
            ans.emplace_back(entry.second);
        }

        return ans;
    }
};