class Solution {
public:
    void addRE(string& num1, int& p1, string& num2, int& p2, int& carry, string& ans){

        if(p1<0 && p2<0){
            if(carry != 0){
                ans.push_back(carry+'0');
            }
            return;
        }

        int n1 = (p1>=0 ? num1[p1] : '0') - '0';
        int n2 = (p2>=0 ? num2[p2] : '0') - '0';
        ans.push_back(char((n1+n2+carry)%10 + '0'));
        carry = (n1+n2+carry)/10;

        addRE(num1, --p1, num2, --p2, carry, ans);
    }

    string addStrings(string num1, string num2) {
        int p1 = num1.length()-1;
        int p2 = num2.length()-1;
        int carry = 0;
        string ans = "";
        
        addRE(num1, p1, num2, p2, carry, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};