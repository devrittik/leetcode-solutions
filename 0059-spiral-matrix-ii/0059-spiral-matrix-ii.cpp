class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rows = n, cols = n;
        int rs = 0, cs = 0, re = rows - 1, ce = cols - 1;
        int lap = 0;
        int x, y, z;
        int el=1;
        int flag = 0;

        vector<vector<int>> matrix(rows, vector<int>(cols,0));

        while (true) {

            if (lap % 2 == 0) {
                x = rs;
                y = cs;
                z = ce;
            } else {
                x = cs;
                y = rs;
                z = re;
            }

            if(rows==1 && flag==1){
                break;
            }

            if (z >= y) {
                for (int i = y; i <= z; i++) {
                    if (lap % 2 == 0) {
                        matrix[x][i] = el;
                    } else {
                        matrix[i][x] = el;
                    }
                    el++;
                }
            } else {
                for (int i = y; i >= z; i--) {
                    if (lap % 2 == 0) {
                        matrix[x][i] = el;
                    } else {
                        matrix[i][x] = el;
                    }
                    el++;
                }
            }

            if (flag == 1) {
                break;
            }

            if (rs == re || cs==ce) {
                flag++;
            }

            switch (lap % 4) {
                case 0:
                    rs++;
                    swap(cs, ce);
                    break;
                case 1:
                    cs--;
                    swap(rs, re);
                    break;
                case 2:
                    rs--;
                    swap(cs, ce);
                    break;
                case 3:
                    cs++;
                    swap(rs, re);
                    break;
            }

            lap++;
        }

        return matrix;
    }
};