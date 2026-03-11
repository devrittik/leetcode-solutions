class Solution {
public:
    static bool magicComp(const string &a, const string &b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numAr;
        for(int& el : nums){
            numAr.emplace_back(to_string(el));
        }

        sort(numAr.begin(),numAr.end(), magicComp);

        if(numAr[0]=="0") return "0";

        string largest;

        for(auto &s : numAr){
            largest+=s;
        }

        return largest;
    }
};