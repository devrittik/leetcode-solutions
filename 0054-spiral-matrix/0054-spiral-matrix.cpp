class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int rs = 0, cs = 0, re = rows - 1, ce = cols - 1;
        int lap = 0;
        int x, y, z;
        int flag = 0;

        vector<int> res;

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
                        res.emplace_back(matrix[x][i]);
                    } else {
                        res.emplace_back(matrix[i][x]);
                    }
                }
            } else {
                for (int i = y; i >= z; i--) {
                    if (lap % 2 == 0) {
                        res.emplace_back(matrix[x][i]);
                    } else {
                        res.emplace_back(matrix[i][x]);
                    }
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

        return res;
    }
};