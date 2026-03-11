class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows==s.length()) return s;

        vector<string> zigzag(numRows);

        int count=0, row=0;
        bool dir=1; //Top->Bottom

        while(count<s.length()){
            if(dir){
                while(row<numRows && count<s.length()){
                    zigzag[row++]+=s[count++];
                }
                row-=2;
            }else{
                while(row>=0 && count<s.length()){
                    zigzag[row--]+=s[count++];
                }
                row+=2;
            }

            dir = !dir;
        }

        string conv;

        for(int i=0; i<numRows; i++){
            conv+=zigzag[i];
        }

        return conv;

    }
};